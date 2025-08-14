class Solution {
public:
    void Paranthesis(vector<string> &v,int open,int close,string op){
        if(open==0 && close==0){
            v.push_back(op);
            return;
        }
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            Paranthesis(v,open-1,close,op1);

        }
        if(open<close){
            string op2=op;
            op2.push_back(')');
            Paranthesis(v,open,close-1,op2);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open=n;
        int close=n;
        string op="";
        Paranthesis(v,open,close,op);
        return v;

    }
};