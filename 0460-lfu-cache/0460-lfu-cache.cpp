class LFUCache {
public:
    int mx,minfreq,currsize;

    class Node{
        public:
        int key,val,cnt;
        Node *prev,*next;
        Node(int k,int v){
            key=k,val=v,cnt=1;
        }
    };
    
    class List{
        public:
        int size;
        Node *head,*tail;
        List(){
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->prev=tail->next=NULL;
            tail->prev=head;
            head->next=tail;
            size=0;
        }
        
        void addnode(Node *node){
            Node*temp1=head->next;
            head->next=node;node->prev=head;
            node->next=temp1;temp1->prev=node;
            size++;
        }
        
        void deletenode(Node *node){
            Node *prevnode=node->prev,*nextnode=node->next;
            prevnode->next=nextnode;
            nextnode->prev=prevnode;
            size--;
        }
        
    };
    
    unordered_map<int,Node*> keymap;
    unordered_map<int,List*> listmap;
    
    LFUCache(int capacity) {
        mx=capacity;
        minfreq=0;currsize=0;
    }
    
    void updFreq(Node *node){
        int cnt=node->cnt;
        listmap[cnt]->deletenode(node);
        if(node->cnt==minfreq and listmap[cnt]->size==0) minfreq+=1;
        
        List* list=new List();
        if(listmap.find(cnt+1)!=listmap.end()){
            list=listmap[cnt+1];
        }
        list->addnode(node);
        node->cnt++;
        listmap[cnt+1]=list;
        keymap[node->key]=node;
    }
    
    int get(int key) {
        if(keymap.find(key)!=keymap.end()){
            Node *node=keymap[key];
            int val=node->val;
            updFreq(node);
            return val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mx==0) return;
        if(keymap.find(key)!=keymap.end()){
            Node *node=keymap[key];
            node->val=value;
            updFreq(node);
        }else{
            if(currsize==mx){
                List *list=listmap[minfreq];
                keymap.erase(list->tail->prev->key);
                list->deletenode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;
            List* list=new List();
            if(listmap.find(minfreq)!=listmap.end()){
                list=listmap[minfreq];
            }
            Node *node=new Node(key,value);
            keymap[key]=node;
            list->addnode(node);
            listmap[minfreq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */