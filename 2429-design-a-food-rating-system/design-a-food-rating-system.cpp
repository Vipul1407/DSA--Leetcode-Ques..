class FoodRatings {
public:

    unordered_map<string,set<pair<int,string>>>st;
    unordered_map<string,string>foodtocus;
    unordered_map<string,int>foodtorating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n= foods.size();
        for(int i=0;i<n;i++)
        {
            foodtorating[foods[i]]= ratings[i];
            foodtocus[foods[i]]= cuisines[i];
            //inserting with minus sign as it will help us to take out the largest and the lexicographically smallest one..
            st[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        string cus= foodtocus[food];
        int old= foodtorating[food];
        st[cus].erase({-old,food});
        st[cus].insert({-newRating,food});
        foodtorating[food]= newRating;
    }
    
    string highestRated(string cuisine) 
    {
        return st[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */