METHOD 1
O(N)


string reverseWord(string str){
    
  //Your code here
  string s="";
  for(int i=str.length()-1;i>=0;i--)
  s=s+str[i];
  
  return s;
}


METHOD-2
O(N)
SWAPPING

string reverseWord(string str){
    
  //Your code here
  int left=0;
  int right=str.length()-1;
  int temp=0;
  while(left<right){
      temp=str[left];
      str[left]=str[right];
      str[right]=temp;
      left++,right--;
      
  }
  
  return str;
}