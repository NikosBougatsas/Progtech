#include <stdexcept>
#include <iostream>

using namespace std;

class Move {
  public:
    Move(int sh, int sc, int th, int tc) {
      shA = sh; scA = sc; thA = th; tcA = tc;
    };

    int getSource() const {
      return shA;
    };

    int getSourceCoins() const {
      return scA;
    };

    int getTarget() const {
      return thA;
    };

    int getTargetCoins() const {
      return tcA;
    };

    friend ostream & operator << (ostream &out, const Move &move) {
      out << "takes " << move.getSourceCoins() << " coins from heap ";
      out << move.getSource() << " and puts ";

      if (move.getTargetCoins() == 0) {
        out << "nothing";
      }
      else {
        out << move.getTargetCoins() << " coins to heap " << move.getTarget();
      }
      return out;
    };
  private:
    int scA, shA, thA, tcA;
};

class State {
  public:
    State (int h, const int c[], int n) {
      A = new int[h];
      heaps = h;
      players = n;
      playing = 0;
      
      for (int i = 0; i < h; i++) {
        A[i] = c[i];
      }
    };

    ~State() {
      delete [] A;
    };

    void next(const Move &move) throw(logic_error) {

      if (A[move.getSource()] < move.getSourceCoins()) {
        throw logic_error("SIERRA");
      }
      else if (move.getSourceCoins() <= move.getTargetCoins()) {
        throw logic_error("BRAVO");
      }
      else if (move.getSource() > heaps || move.getTarget() > heaps || move.getSource() < 0 || move.getTarget() < 0) {
        throw logic_error("FOXTROT");
      }
      A[move.getSource()] -= move.getSourceCoins();
      A[move.getTarget()] += move.getTargetCoins();
      playing = (playing + 1) % players;
    };

    bool winning() const {
      for (int i = 0; i < heaps; i++) {
        if (A[i] != 0) return false;
      }
      return true;
    };

    int getHeaps() const {
      return heaps;
    };

    int getCoins(int h) const throw(logic_error) {
      if (h < 0 || h >= heaps) throw logic_error("GOLF");
      return *(A + h);
    };

    int getPlayers() const {
      return players;
    };
  
    int getPlaying() const {
      return playing;
    };

    friend ostream & operator << (ostream &out, const State &state) {
      out << state.getCoins(0);

      for (int i = 1; i < state.getHeaps(); i++) {
        out << ", " << state.getCoins(i);
      }

      out << " with " << state.getPlaying();
      out << "/" << state.getPlayers() << " playing next";
      return out;
    };
  private:
    int *A;
    int players, heaps, playing;
};

#define MIN 10000010

class Player {
  public:
    Player(const string &n) {
      name = n;
    };

    virtual ~Player() {};

    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player) {
      out << player.getType() << " player " << player.name;
      return out;
    };
  private:
    string name;
};

class GreedyPlayer : public Player {
  public:
    GreedyPlayer(const string &n) : Player(n) {
      type = "Greedy";
    };
  
    virtual const string & getType() const override {
      return type;
    };

    virtual Move play(const State &s) {
      int max = 0, maxpos = 0;
      for (int i = 0; i < s.getHeaps(); i++) {
        if (s.getCoins(i) > max) {
          max = s.getCoins(i); maxpos = i;
        }
      }
      return Move(maxpos, max, 0, 0);
    };
  private:
    string type;
};

class SpartanPlayer : public Player {
  public:
    SpartanPlayer (const string &n) : Player(n) {
      type = "Spartan";
    };

    virtual const string & getType() const override {
      return type;
    };

    virtual Move play(const State &s) {
      int max = 0, maxpos = 0;
      for (int i = 0; i < s.getHeaps(); i++) {
        if (s.getCoins(i) > max) {
          max = s.getCoins(i); maxpos = i;
        }
      }
      return Move(maxpos, 1, 0, 0);
    };
  private:
    string type;
};

class SneakyPlayer : public Player {
  public:
    SneakyPlayer(const string &n) : Player(n) {
      type = "Sneaky";
    };

    virtual const string & getType() const override {
      return type;
    };

    virtual Move play(const State &s) {
      int min = MIN, minpos = 0;
      for (int i = 0; i < s.getHeaps(); i++) {
        if (s.getCoins(i) < min && s.getCoins(i) > 0) {
          min = s.getCoins(i); minpos = i;
        }
      }
      return Move(minpos, min, 0, 0);
    };
  private:
    string type;
};

class RighteousPlayer : public Player {
  public:
    RighteousPlayer(const string &n) : Player(n) {
      type = "Righteous";
    };

    virtual const string & getType() const override {
      return type;
    };

    virtual Move play(const State &s) {
      int max = 0, maxpos = 0, min = MIN, minpos = 0;
      for (int i = 0; i < s.getHeaps(); i++) {
        if (s.getCoins(i) > max) {
          max = s.getCoins(i); maxpos = i;
        }
      }
      for (int i = 0; i < s.getHeaps(); i++) {
        if (s.getCoins(i) < min) {
          min = s.getCoins(i); minpos = i;
        }
      }
      return Move(maxpos, (max + 1)/2, minpos, (max + 1)/2 - 1);
    };
  private:
    string type;
};

class Game {
  public:
    Game(int heaps, int players) {
      gameHeaps = heaps; gamePlayers = players;
      heapFill = 0; playerFill = 0;
      heap = new int[gameHeaps];
      players1 = new Player*[gamePlayers];
    };

    ~Game() {
      delete [] heap;
      delete [] players1;
    };

    void addHeap(int coins) throw(logic_error) {
      if (coins < 0) {
        throw logic_error("XRAY");
      }
      *(heap + heapFill) = coins;
      heapFill++;
    };

    void addPlayer(Player *player) throw(logic_error) {
      *(players1 + playerFill) = player;
      playerFill++;
    };

    void play(ostream &out) throw(logic_error) {
      State s(gameHeaps, heap, gamePlayers);

      while (!s.winning()) {
        out << "State: " << s << endl;
        out << *getPlayer(s.getPlaying()) << " ";
        out << (**(players1 + s.getPlaying())).play(s) << endl;
        s.next((**(players1 + s.getPlaying())).play(s));
      }
      out << "State: " << s << endl;
      int w;
      if (s.getPlaying() == 0) {
        w = gamePlayers - 1;
      }
      else {
        w = s.getPlaying() - 1;
      }
      out << **(players1 + w) << " wins" << endl;
    };

    int getPlayers() const {
      return gamePlayers;
    };

    const Player *getPlayer(int p) const throw(logic_error) {
      if (p < 0 || p >= gamePlayers) {
        throw logic_error("ZULU");
      }
      return *(players1 + p);
    };

  private:
    int gameHeaps, gamePlayers, playerFill, heapFill;
    int *heap;
    Player **players1;
};

int main() {
  Game specker(3, 4);
  specker.addHeap(10);
  specker.addHeap(20);
  specker.addHeap(17);
  specker.addPlayer(new SneakyPlayer("Tom"));
  specker.addPlayer(new SpartanPlayer("Mary"));
  specker.addPlayer(new GreedyPlayer("Alan"));
  specker.addPlayer(new RighteousPlayer("Robin"));
  specker.play(cout);

  return 0;
}
