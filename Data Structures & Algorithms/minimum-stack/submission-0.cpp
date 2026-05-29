class MinStack {
        vector<int> main_sta;
        vector<int> min_sta;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(main_sta.size()==0){
            main_sta.push_back(val);
            min_sta.push_back(val);
        }
        else{
            main_sta.push_back(val);
            min_sta.push_back(min(min_sta.back(),val));
        }
    }
    
    void pop() {
        main_sta.pop_back();
        min_sta.pop_back();

    }
    
    int top() {
        return main_sta.back();
    }
    
    int getMin() {
        int num = 0;
        return min_sta.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */