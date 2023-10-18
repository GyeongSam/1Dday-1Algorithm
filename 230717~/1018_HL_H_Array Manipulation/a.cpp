void AddQuery(map<int,long>& preFixSum, int target, int value){
    if (preFixSum.find(target)!=preFixSum.end()){
        preFixSum[target]+=value;
    }
    else preFixSum[target]=value;
}


long arrayManipulation(int n, vector<vector<int>> queries) {
    map<int,long> preFixSum;
    for (const vector<int>& v : queries){
        AddQuery(preFixSum,v[0],v[2]);
        AddQuery(preFixSum,v[1]+1,-v[2]);
    }
    long sum=0;
    long maxValue=0;
    for (auto value : preFixSum){
        sum+=value.second;
        if (sum>maxValue) maxValue = sum;
    }
    return maxValue;
}