// Tyler Baker
// 4.21.15
// Members.h 1.0

#include "Member.h"
using namespace std;

Member::Member()
{
  members = new MemberData[arraySize];
}

Member::~Member()
{

}

Member::Member(const Member &rhs)
{

}

Member& Member::operator=(const Member &rhs)
{

  return *this;
}

string Member::getName(int index)
{
  return members[index].name;
}
string Member::getUsername(int index)
{
  return members[index].username;
}

int Member::getMemberCount()
{
  return memberCount;
}

int Member::addMember(string nameIn, string usernameIn)
{
  char badUsernameCatch;
  bool usernameGood = false;
  int memberIndex;
  
  while(!usernameGood){
    usernameGood = true;
    for(int i = 0; i < memberCount; i++){
	  
      if(members[i].username == usernameIn && 
		 (usernameGood)){
        usernameGood = false;
		
        cout << "The username " << usernameIn << " is already in use" << endl;
        cout << "Would you like to change the username (i) or cancel (c)? "
             << "(i/c) ";
        cin >> badUsernameCatch;
        if(badUsernameCatch == CHANGE){
          cout << endl << "Please enter a new username: ";
          cin >> usernameIn;
        }
        else
          return -1;
      }
    }
  }
  
  if(memberCount == arraySize){
	int newSize = arraySize * 1.5;
	
	MemberData *newArr = new MemberData[newSize];
	
	for(int i = 0; i < arraySize; i++)
	  newArr[i] = members[i];
	
	arraySize = newSize;
	
	delete [] members;
	members = newArr;
	memberIndex = memberCount;
	//memberCount++;
  }
  
  members[memberCount].name = nameIn;
  members[memberCount].username = usernameIn;
  
  cout << members[memberCount].name << "|" << members[memberCount].username << 
	"|" << memberCount << endl;

  memberIndex = memberCount;
  memberCount++;
  return memberIndex;
  
}

bool Member::login(string username, int &login)
{
  for(int i = 0; i < memberCount; i++){
	if(members[i].username == username){
	  login = i;
	  return true;
	}
	else{
	  cout << "The user does not exist, please create the user first" << endl;
	  return false;
	  
	}
  }
  return false;
}
