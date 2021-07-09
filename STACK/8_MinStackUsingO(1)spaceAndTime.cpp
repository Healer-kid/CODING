O(1) SPACE AND O(1) TIME
/*
push:
ce: 2x-minele
pop:  
min:2minele-y
*/





void pop()
    {
        if (s.empty())
        {
           
            return;
        }
  
       
        int y = s.top();
        s.pop();
  
        
        if (y < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - y;
        }
  
        else
            cout << y << "\n";
    }
  
   
    void push(int x)
    {
        
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            return;
        }
  
        					// If new number is less than minEle
        if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
  
        else
           s.push(x);
  
       
    }