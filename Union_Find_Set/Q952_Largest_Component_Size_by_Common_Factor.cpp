
//using union-find set and accelerate the performance

class Union_Find_Set {
public:
    Union_Find_Set(int size) {
        parents = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    void Union(int a, int b) {
        parents[find(a)] = find(b);
    }

    int find(int index) {
        if (parents[index] != index) {
            parents[index] = find(parents[index]);
        }
        return parents[index];
    }

private:
    vector<int> parents;
};


class Solution {
public:
    int largestComponentSize(vector<int> &A) {
        //first compute all the primes between 1 to sqrt(max(A)).
        int len = A.size();
        if (len == 0) return 0;
        int n = *max_element(A.begin(), A.end());
        Union_Find_Set s = Union_Find_Set(n + 1);
        for (auto a : A) {
            for (int i = 2; i <= sqrt(a); ++i) {
                if (a % i == 0) {
                    s.Union(i, a);
                    s.Union(a / i, a);
                }
            }
        }

        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++mp[s.find(a)]);
        }
        return ans;
    }

};
