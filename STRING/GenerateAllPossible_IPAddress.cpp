Program to generate all possible valid IP addresses from given string
Difficulty Level : Hard
Last Updated : 25 Jan, 2021
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Examples :

Input: 25525511135
Output: [“255.255.11.135”, “255.255.111.35”]
Explanation:
These are the only valid possible
IP addresses.

Input: "25505011535"
Output: []
Explanation: 
We cannot generate a valid IP
address with this string.
First, we will place 3 dots in the given string and then try out all the possible combinations for the 3 dots. 
Corner case for validity:

For string "25011255255"
25.011.255.255 is not valid as 011 is not valid.
25.11.255.255 is not valid either as you are not
allowed to change the string.
250.11.255.255 is valid.






TIME:O(N^3)
SPACE:O(N)


1.NO LEADING ZEROS
2.RANGE SHOULD BE 0 - 255
3.4 CELLS
4. ONLY INTEGERS








// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
	// Splitting by "."
	vector<string> ips;
	string ex = "";
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == '.') {
			ips.push_back(ex);
			ex = "";
		}
		else {
			ex = ex + ip[i];
		}
	}
	ips.push_back(ex);

	// Checking for the corner cases
	// cout << ip << endl;
	for (int i = 0; i < ips.size(); i++) {
		// cout << ips[i] <<endl;
		if (ips[i].length() > 3
			|| stoi(ips[i]) < 0
			|| stoi(ips[i]) > 255)
			return 0;

		if (ips[i].length() > 1
			&& stoi(ips[i]) == 0)
			return 0;

		if (ips[i].length() > 1
			&& stoi(ips[i]) != 0
			&& ips[i][0] == '0')
			return 0;
	}
	return 1;
}

// Function converts string to IP address
void convert(string ip)
{
	int l = ip.length();

	// Check for string size
	if (l > 12 || l < 4) {
		cout << "Not Valid IP Address";
	}

	string check = ip;
	vector<string> ans;

	// Generating different combinations.
	for (int i = 1; i < l - 2; i++) {
		for (int j = i + 1; j < l - 1; j++) {
			for (int k = j + 1; k < l; k++) {
				check = check.substr(0, k) + "."
						+ check.substr(k);
				check
					= check.substr(0, j) + "."
					+ check.substr(j);
				check
					= check.substr(0, i) + "."
					+ check.substr(i);

				// cout<< check <<endl;
				// Check for the validity of combination
				if (is_valid(check)) {
					ans.push_back(check);
					std::cout << check << '\n';
				}
				check = ip;
			}
		}
	}
}

// Driver code
int main()
{
	string A = "1110110";
	string B = "25505011535";

	convert(A);
	convert(B);

	return 0;
}

OUTPUT

1) 

1.1.10.110
1.1.101.10
1.11.0.110
1.110.1.10
1.110.11.0
11.1.0.110
11.10.1.10
11.10.11.0
11.101.1.0
111.0.1.10
111.0.11.0


2) NO OUTPUT
