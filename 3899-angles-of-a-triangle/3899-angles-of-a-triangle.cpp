class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        // Check triangle validity
        if (a + b > c && b + c > a && a + c > b) {

            double A = acos((b*b + c*c - a*a) / (2.0*b*c));
            double B = acos((a*a + c*c - b*b) / (2.0*a*c));
            double C = acos((a*a + b*b - c*c) / (2.0*a*b));

            // Convert to degrees
            A = A * 180.0 / M_PI;
            B = B * 180.0 / M_PI;
            C = C * 180.0 / M_PI;
            vector<double>ans;
            ans.push_back(A);
            ans.push_back(B);
            ans.push_back(C);
            sort(ans.begin(),ans.end());
            return ans;
        }

        return {};
    }
};