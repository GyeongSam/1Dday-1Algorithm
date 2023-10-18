int min(int a, int b){
    return a>b?b:a;
}
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    const int INC = r_q-c_q;
    const int DEC = r_q+c_q;
    int U=n-r_q, D=r_q-1, L=c_q-1, R=n-c_q;
    int UL=min(U,L), UR=min(U,R), DL=min(D,L), DR=min(D,R);
    
    for (const vector<int> roc : obstacles){
        if (roc[0]==r_q){
            if (roc[1]>c_q){
                R = min(R,roc[1]-c_q-1);
            }
            else {
                L = min(L,c_q-roc[1]-1);
            }
        }
        else if (roc[1]==c_q){
            if (roc[0]>r_q){
                U = min(U,roc[0]-r_q-1);
            }
            else{
                D = min(D,r_q-roc[0]-1);
            }
        }
        else if (roc[0]-roc[1]==INC){
            if (roc[0]>r_q){
                UR = min(UR,roc[0]-r_q-1);
            }
            else{
                DL = min(DL,r_q-roc[0]-1);
            }
            
        }
        else if (roc[0]+roc[1]==DEC){
            if (roc[0]>r_q){
                UL = min(UL,roc[0]-r_q-1);
            }
            else{
                DR = min(DR,r_q-roc[0]-1);
            }
        }
    }
    return D+U+L+R+DL+DR+UL+UR;
}