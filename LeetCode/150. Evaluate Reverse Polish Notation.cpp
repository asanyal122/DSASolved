class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token:tokens)
        {
            if(token=="+" || token=="*" || token=="-" || token=="/")
            {
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                char tok=token[0];
                cout<<op1<<" "<<op2<<"\n";
                switch(tok)
                {
                    case '+':s.push(op1+op2);break;
                    case '-':s.push(op2-op1);break;
                    case '*':s.push(op1*op2);break;
                    case '/':s.push((int)(op2/op1));break;
                }
                    
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
