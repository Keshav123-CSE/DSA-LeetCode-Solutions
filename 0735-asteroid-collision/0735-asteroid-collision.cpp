class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> st;

        for (int asteroid : asteroids) {

            // Handle collisions
            while (!st.empty() && 
                   st.back() > 0 && 
                   asteroid < 0) {

                // Left asteroid is smaller
                if (st.back() < -asteroid) {
                    st.pop_back();
                    continue;
                }

                // Both asteroids have same size
                else if (st.back() == -asteroid) {
                    st.pop_back();
                }

                // New asteroid is destroyed
                asteroid = 0;
                break;
            }

            // If current asteroid survives
            if (asteroid != 0) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};