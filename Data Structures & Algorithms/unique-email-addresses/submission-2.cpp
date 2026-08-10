class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            string cleaned  ="";

            int i = 0;

            while (email[i] != '@') {
                if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                    break;
                }
                if (email[i] != '.') {
                    cleaned += email[i];
                }
                i++;
            }
            while (i < email.length()) {
                cleaned += email[i];
                i++;
            }
            uniqueEmails.insert(cleaned);        
        }
         return uniqueEmails.size();

    }
   
};