#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <pthread.h>
#include <unistd.h>

using namespace std;

struct arguments{
  int input;
  string output;
};


void* oddOrEven(void* arg_ptr){
  //dereference the arg_ptr
  struct arguments* argu = (struct arguments*)arg_ptr;

  //implement the answer to output
  if (argu->input % 2 == 0){
    argu->output = "Even";
  }
  else if (argu->input % 2 == 1){
    argu->output = "Odd";
  }

  return nullptr;
}

int main(){
  vector <int> nums;
  string strNum;

  cin >> strNum;

  for (int i=0; i<strNum.length(); i++){
    nums.push_back(strNum[i] - '0');
  }

  struct arguments args[strNum.length()]; //set the size of args
  pthread_t tid[nums.size()]; //set the size of threads

  //example: "1234"
  //vector - {1, 2, 3, 4}
  for (int i=0; i<nums.size(); i++){ //loop 4 times with the example of "1234"
    args[i].input = nums[i];//set the inputs into individual argument
    //pthread_create here
    if (pthread_create(&tid[i], nullptr, oddOrEven, &args[i])){
      fprintf(stderr, "Error creating thread\n");
            return 1;
    }
  }

  //pthread_join here
  for (int i=0; i<nums.size(); i++){
    pthread_join(tid[i], nullptr);
  }

  for (int i=0; i<nums.size(); i++){
    cout << args[i].output << " ";
  }
}