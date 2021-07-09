Expression contains redundant bracket or not

Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.

Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

found task
1) take care of immediate parenthesis eg) (b)

2)take care of redundant parenthesis  eg) ((a+b))


IDEA
if operators or '(' ==> then push
if ')' ,check for immediate and check for redundant brackets 




bool redundancy(){
bool ans=false;
stack<char> st;
for(int i=0;i<s.length();i++){
if(s[i]=='(')
st.push(s[i]);
else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
st.push(s[i]);
else if(s[i]==')')
{
	if(st.top()=='(')
	ans=true;
	while((st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')
	st.pop();
	st.pop()  //REMOVAL OF '(' SO THAT IT WONT AFFECT IN THE NEXT ITERATION	
	
}

}


}