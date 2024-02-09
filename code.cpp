class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node* , int>>q;
        q.push({root , 0});
        map<int , int>m;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int line=it.second;
            Node *node=it.first;
            if(m.find(line)==m.end()){
                m[line]=node->data;
            }
            if(node->left!=NULL){
                q.push({node->left  , line-1});
            }
             if(node->right!=NULL){
                q.push({node->right  , line+1});
            }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
    

};
