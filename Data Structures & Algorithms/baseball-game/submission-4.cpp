class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> rec;
        int top=rec.size();
        int num = 0;
        int sum = 0;
        for (int i=0; i<operations.size(); i++){
            if (operations[i]=="D"){
                num = 2*rec[top-1];
                sum+=num;
                rec.push_back(num);
                top+=1;
            }
            else if(operations[i]=="C"){
                sum-=rec[top-1];
                rec.pop_back();
                top-=1;
            }
            else if(operations[i]=="+"){
                num=rec[top-1]+rec[top-2];
                sum+=num;
                rec.push_back(num);
                top+=1;
            }
            else{
                num=stoi(operations[i]);
                sum+=num;
                rec.push_back(num);
                top+=1;
            }
        }

        return sum;


    }
};