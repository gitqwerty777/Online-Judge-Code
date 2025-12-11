#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int maxstatement = 50;

//name, his statement, day, type(-> lie),
char possiblestr[][3][15] = {{"divine", "human", "evil"}, {"day", "night"}, {"is lie", "is not lie"}};
enum STATE{UNKNOWN=-1, COMFIRMED=1, BUSTED=0};
enum TYPE{UNKNOWNTYPE=-1, DIVINE=0, HUMAN=1, EVIL=2};
enum LIE{UNKNOWNLIE=-1, ISLIE=0, NOTLIE=1};
enum DAY{UNKNOWNDAY=-1, ISDAY=0, NIGHT=1};
struct State{//statement of a person stated by a person
  bool isTrue;
  STATE isLie;
  STATE isType[3];
  STATE isDay[2];
  
  State(){
    init();
  }
  void init(){
    isLie = UNKNOWN;
    isType[0] = isType[1] = isType[2] = UNKNOWN;
    isDay[0] = isDay[1] = UNKNOWN;
  }
  void setType(int index, bool b){
    if(b){
      for(int i = 0; i < 3; i++)
	if(i == index)
	  isType[i] = COMFIRMED;
	else
	  isType[i] = BUSTED;
    } else {
      isType[index] = BUSTED;
    }
  }
  void setLie(bool b){
    if(b)
      isLie = COMFIRMED;
    else
      isLie = BUSTED;
  }
  void print(){
    for(int i = 0; i < 3; i++)
      if(isType[i] == COMFIRMED)
	printf("%s is true\n", possiblestr[0][i]);
      else if(isType[i] == BUSTED)
	printf("%s is false\n", possiblestr[0][i]);
    //
    if(isLie == COMFIRMED)
      printf("%s is true\n", possiblestr[2][0]);
    else if(isLie == BUSTED)
      printf("%s is false\n", possiblestr[2][1]);
  }

  bool fill(State s){
    for(int i = 0; i < 3; i++)
      if(s.isType[i] == COMFIRMED && isType[i] == BUSTED || s.isType[i] == BUSTED && isType[i] == COMFIRMED)
	return false;
      else if(s.isType[i] != UNKNOWN)
	isType[i] = s.isType[i];
    if(s.isLie == COMFIRMED && isLie == BUSTED || s.isLie == BUSTED && isLie == COMFIRMED)
      return false;
    else if(s.isLie != UNKNOWN)
      isLie = s.isLie;
    return true;
  }

  bool checkTrue(int day){
    if(isType[EVIL] == COMFIRMED || (isType[DIVINE] == BUSTED && day == NIGHT) || isLie == COMFIRMED || isType[HUMAN] == COMFIRMED && day == NIGHT)
      return false;
    return true;
  }
  bool checkFalse(int day){
    if(isType[DIVINE] == COMFIRMED || (isType[HUMAN] == COMFIRMED && day == ISDAY) || isLie == BUSTED || isType[EVIL] == BUSTED && day == ISDAY)
      return false;
    return true;
  }
  void reverse(){
    if(isLie == COMFIRMED)
      isLie = BUSTED;
    else if(isLie == BUSTED)
      isLie = COMFIRMED;

    //COMFIRMED -> BUSTED, BUSTED -> UNKNOWN, UNKNOWN -> COMFIRMED;
    //if true statement -> cbbbbbb, false -> uuuubuu
    //   reversed       -> buuuuuu, false -> bbbbcbb
    if(isComfirmedType()){
      for(int i = 0; i < 3; i++){
	if(isType[i] == COMFIRMED)
	  isType[i] = BUSTED;
	else
	  isType[i] = UNKNOWN;
      }
    } else {
      for(int i = 0; i < 3; i++){
	if(isType[i] == BUSTED)
	  isType[i] = COMFIRMED;
	else
	  isType[i] = BUSTED;
      }
    }
  }
  bool isComfirmedType(){
    for(int i = 0; i < 3; i++)
      if(isType[i] == COMFIRMED)
	return true;
    return false;
  }
};

struct MyState{//statement of all people and day which stated by a person
  int day;//SHOULD put in State
  struct State state[5];

  MyState(){
    day = UNKNOWNDAY;
  }
  void init(){
    day = UNKNOWNDAY;
    for(int i = 0; i < 5; i++)
      state[i].init();
  }
  void setType(int subject, int type, bool istrue){
    printf("set type %d -> %d, (%s)\n", subject, type, istrue?"true":"false");
    state[subject].setType(type, istrue);
  }
  void setLie(int subject, bool istrue){
    state[subject].setLie(istrue);
  }
  void setDay(int type, bool istrue){
    if(istrue){
      if(type == ISDAY)
	day = ISDAY;
      else
	day = NIGHT;
    } else{
      if(type == ISDAY)
	day = NIGHT;
      else
	day = ISDAY;
    }
  }
  void print(){
    if(day != UNKNOWN)
      printf("day = %d\n", day);
    for(int i = 0; i < 5; i++){
      printf("person %c:\n", 'A'+i);
      state[i].print();
    }
  }
  bool fill(MyState s){
    if(day != UNKNOWN && s.day != UNKNOWN && day != s.day){
      return false;
    }
    for(int i = 0; i < 5; i++)
      if(!state[i].fill(s.state[i]))
	return false;
  }
  bool checkPossible(bool isTrue[]){
    bool isPossible = true;
    for(int i = 0; i < 5 && isPossible; i++){
      if(isTrue[i])
	isPossible = isPossible && state[i].checkTrue(day);
      else
	isPossible = isPossible && state[i].checkFalse(day);
    }
    return isPossible;
  }
  MyState reverse(){
    MyState newState = *this;
    if(newState.day != UNKNOWN){
      if(newState.day == ISDAY)
	newState.day = NIGHT;
      else
	newState.day = ISDAY ;
    }
    for(int i = 0; i < 5; i++)
      newState.state[i].reverse();
  }
  void ComfirmedInit(){
    day = ISDAY;
    for(int i = 0; i < 5; i++)
      state[i].init();
  }
  void fillComfirmed(MyState& s){//TODO:
    if(s.day == UNKNOWN)
      return;
  }
};

struct TotalState{
  TotalState(){
    pnum = 0;
    nowTableIndex = 0;
  }
  bool isTrue[5];
  int nowTableIndex;
  int pnum;
  MyState personalState[5];//for A, B, C, D, E

  void init();
  bool inference();
  void parse(char s[]);
  bool fillTruthTable(int pnum);
};

void TotalState::init(){

}


void TotalState::parse(char s[]){
  /*
    X: I am [not] ( divine | human | evil | lying ).  
    X: X is [not] ( divine | human | evil | lying ).  
    X: It is ( day | night ).  
 */
  char *p = strtok(s, ":"); puts(p);
  int claimer = p[0] - 'A';

  p = strtok(NULL, " "); puts(p);
  int subject;
  if(p[0] != 'I')
    subject = p[0] - 'A';
  else {
    if(p[1] != 't')//I
      subject = claimer;
    else//It
      subject = 0;//no need to set
  }
  
  bool isTrue = true;
  p = strtok(NULL, ". ");
  MyState mystate = personalState[claimer];
  while(p != NULL){
    puts(p);
    if(strcmp(p, "not") == 0)
      isTrue = false;
    else if(strcmp(p, "divine") == 0)
      mystate.setType(subject, DIVINE, isTrue);
    else if(strcmp(p, "human") == 0)
      mystate.setType(subject, HUMAN, isTrue);
    else if(strcmp(p, "evil") == 0)
      mystate.setType(subject, EVIL, isTrue);
    else if(strcmp(p, "lying") == 0)
      mystate.setLie(subject, isTrue);
    else if(strcmp(p, "day") == 0)
      mystate.setDay(ISDAY, isTrue);
    else if(strcmp(p, "night") == 0)
      mystate.setDay(NIGHT, isTrue);
    p = strtok(NULL, ". ");
  }
  mystate.print();
}

bool TotalState::fillTruthTable(int pnum){
  int num = nowTableIndex;
  for(int i = 0; i < pnum; i++){
    isTrue[i] = (num%2 == 0);
    num /= 2;
  }
  nowTableIndex++;
}

bool TotalState::inference(){// if only one possible type/lie/day, print it
  int pnum = 5;
  nowTableIndex = 0;
  MyState comfirmedState;
  MyState testState;
  while(fillTruthTable(pnum)){
    bool isPossible = true;
    testState.init();
    for(int i = 0; i < pnum && isPossible; i++){
      if(isTrue[i]){
	isPossible = isPossible && testState.fill(personalState[i]);
      } else {
	isPossible = isPossible && testState.fill(personalState[i].reverse());//he is liar
      }
    }
    if(isPossible && testState.checkPossible(isTrue)){
      comfirmedState.fillComfirmed(testState);
    }
  }
}

bool TotalState::checkPossible(){
  return true;
}

int N;
char s[100];
TotalState state;
int main(){
  while(scanf("%d\n", &N) == 1 && N){
    state.init();
    for(int i = 0; i < N; i++){
      gets(s);
      state.parse(s);
    }
    state.inference();
  }
}
