void matrixRotation(vector<vector<int>> matrix, int r) {
    int mi=0, mj=0, Mi=matrix.size()-1, Mj=matrix[0].size()-1;
    vector<deque<int>> transMat;
    while(mi<Mi&&mj<Mj){
        deque<int> dq;
        int si=mi,sj=mj;
        while(si<Mi){
            dq.push_back(matrix[si][sj]);
            si++;
        }
        while(sj<Mj){
            dq.push_back(matrix[si][sj]);
            sj++;
        }
        while(si>mi){
            dq.push_back(matrix[si][sj]);
            si--;
        }
        while(sj>mj){
            dq.push_back(matrix[si][sj]);
            sj--;
        }
        transMat.push_back(dq);
        mi++;Mi--;mj++;Mj--;
    }
    for (deque<int>& dq : transMat){
        int cnt = r%dq.size();
        while(cnt--){
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    vector<vector<int>> answer(matrix.size(),vector<int>(matrix[0].size()));
    mi=0,Mi=matrix.size()-1,mj=0,Mj=matrix[0].size()-1;
    for (deque<int>& dq :transMat){
        int si=mi,sj=mj;
        while(si<Mi){
            answer[si][sj]=dq.front();
            dq.pop_front();
            si++;
        }
        while(sj<Mj){
            answer[si][sj]=dq.front();
            dq.pop_front();
            sj++;
        }
        while(si>mi){
            answer[si][sj]=dq.front();
            dq.pop_front();
            si--;
        }
        while(sj>mj){
            answer[si][sj]=dq.front();
            dq.pop_front();
            sj--;
        }
        mi++;Mi--;mj++;Mj--;
    } 
    for (int i=0; i<matrix.size();++i){
        for (int j=0; j<matrix[0].size();++j){
            printf("%d ",answer[i][j]);
        }
        printf("\n");
    }
    
}