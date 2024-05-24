class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        vector<Node*> v;
        q.push(root);
        v.push_back(root);
        v.push_back(NULL);
        q.push(NULL);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    v.push_back(front);
                }
            }
            else{
                if(front->left){
                    q.push(front->left);
                    v.push_back(front->left);
                }
                if(front->right){
                    q.push(front->right);
                    v.push_back(front->right);
                }
            }
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=NULL && v[i+1]!=NULL){
                v[i]->next=v[i+1];
            }
            else if(v[i]!=NULL && v[i+1]==NULL){
                v[i]->next=NULL;
            }
        }
        
        return root;
    }
};