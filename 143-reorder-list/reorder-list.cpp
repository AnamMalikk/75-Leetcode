/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head1) {
        ListNode *head=head1;
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        ListNode *root=new ListNode(0);
        ListNode *current=root;
        int l=0,r=v.size()-1;
        int cnt=1;
        while(cnt<=v.size()){
            ListNode *tem=nullptr;
            if(cnt%2==1){
                tem=new ListNode(v[l]);
                l++;
            }
            else{
                tem=new ListNode(v[r]);
                r--;
            }
            current->next=tem;
            cnt++;
            current=current->next;
        }
        current=root;
        root=root->next;
        delete current;
        head=head1;
        while(root){
            head->val=root->val;
            head=head->next;
            root=root->next;
        }
    }
};