#ifndef NODE_H
#define NODE_H
class Node{
    private:
        Node *next;
        int date;
    public:
        Node(const int &date, Node *next);
        void *insertAfter(Node &p);
        Node *deleteAfter();
        Node *nextNode();
        const Node *nextNode() const;
};
Node::Node(const int &date,Node *next):date(date),next(next){}
void Node::insertAfter(Node &p){
    p->next = next;
    next = p;
}
Node *Node::deleteAfter(){
    Node *tempPtr = next;
    if(next==0)
        return 0;
    next = tempPtr->next;
    return tempPtr;
}
Node *Node::nextNode(){
    return next;
}
const Node *Node::nextNode()const{
    return next;
}
#endif
