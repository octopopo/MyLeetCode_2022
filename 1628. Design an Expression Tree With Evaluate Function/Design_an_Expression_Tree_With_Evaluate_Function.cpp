/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
    
};

class NumberNode : public Node{
    public:
    NumberNode(int i){
        val = i;
    }
    
    int evaluate() const override {
        return val;
    }
    
    protected:
    int val;
};

template <class T>
class WorkNode : public Node{
    public:
    WorkNode(Node*  leftC, Node* rightC){
        left = leftC;
        right = rightC;
    }
    
    int evaluate() const override{
        return T()(left->evaluate(), right->evaluate());
    }
    
    protected:
    Node* left;
    Node* right;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        int pL = postfix.size();
        string tempS;
        stack<Node*> numberStack;
        
        for(int i =  0; i < pL;  i++){
            tempS = postfix[i];
            
            if(isdigit(tempS[0])){
                //NumberNode* newNumber = new NumberNode(stoi(tempS));
                numberStack.push(new NumberNode(stoi(tempS)));
                continue;
            }
            
            Node* left;
            Node* right;
            
            right = numberStack.top();
            numberStack.pop();
            left = numberStack.top();
            numberStack.pop();
            
            if(tempS[0] == '+'){
                numberStack.push(new WorkNode<plus<int>>(left, right));
            }
            else if(tempS[0] == '-'){
                numberStack.push(new WorkNode<minus<int>>(left, right));
            }
            else if(tempS[0] == '*'){
                numberStack.push(new WorkNode<multiplies<int>>(left, right));
            }
            else if(tempS[0] == '/'){
                numberStack.push(new WorkNode<divides<int>>(left, right));
            }
        }
        
        return numberStack.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */