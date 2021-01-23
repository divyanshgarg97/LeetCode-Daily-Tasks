class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //Logic 2
        int n = mat.size();
        int m = mat[0].size();
        for(int k = 0 ; k < m ;k++) {
            vector<int> temp;
            for(int i = 0 , j = k ; i < n && j < m ;i++,j++){
                temp.push_back(mat[i][j]);
            }
            int w = 0;
            sort(temp.begin(),temp.end());
            for(int i = 0, j = k ;i < n && j < m ;i++,j++){
                mat[i][j] = temp[w];
                w++;
            }
        }
        for(int k = 1; k < n ;k++) {
            vector<int> temp;
            for(int i = k , j = 0 ; i < n && j < m;i++,j++){
                temp.push_back(mat[i][j]);
            }
            int w =0;
            sort(temp.begin(),temp.end());
            for(int i = k , j = 0 ;i <n && j < m ;i++,j++){
                mat[i][j] = temp[w];
                w++;
            }
        }
        return mat;
        // Logic 1
        // map<int,vector<int> > mp;
        // for(int i = 0 ;i <mat.size() ;i++) {
        //     for(int j = 0 ;j < mat[0].size();j++) {
        //         mp[i-j].push_back(mat[i][j]);
        //     }
        // }
        // for(auto &i : mp) {
        //     sort(i.second.begin(),i.second.end());
        //     for(int k = 0 ; k < i.second.size() ;k++) {
        //         cout<< i.second[k] << " ";
        //     }
        //     //mp[i.first] = i.second;
        //     //cout << endl;
        // }
        // map<int,int> mp2;
        // //memset(arr,0,sizeof(arr));
        // for(int i = 0 ;i < mat.size();i++) {
        //     for(int j = 0 ;j < mat[0].size();j++) {
        //         if(mp2.find(i-j) == mp2.end()) 
        //             mp2[i-j] = 0;
        //         mat[i][j] = mp[i-j][mp2[i-j]];
        //         //cout<< "i " <<i << " j " << j << " value given " << mp[i-j][mp2[i-j]] << endl;
        //         mp2[i-j]++;
        //     }
        // }
        // return mat;
    }
};