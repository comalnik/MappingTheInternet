#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

//OK
int ping_ip(string ip) {
    int x = system(("ping -c 1 -W 5 " + ip + " > /dev/null 2>&1").c_str());
        if (x == 0) {
            return 1;
        }
        else {
            return 0;
        }
}

//TODO
int ping_ip_range(string start_ip, string end_ip) {
    
}


//OK
unsigned int ip_to_int(int ip[]) {
    unsigned int startIP = (
        ip[0] << 24 |
        ip[1] << 16 | 
        ip[2] << 8 |
        ip[3]);
    return startIP;
}


//TODO
 int int_to_ip(int ip) {



}


//TODO (change from void-printf to return array)
void ips_array(int start, int end) {
    for (int i = start; i <= end; i++) {
        printf (" %d.%d.%d.%d\n",
            (i & 0xFF000000)>>24,
            (i & 0x00FF0000)>>16,
            (i & 0x0000FF00)>>8,
            (i & 0x000000FF)
        );
    }


}


//OK
void stringtoarray(const string& ipString, int ipArray[]) {
    istringstream ss(ipString);
    string token;
    int i = 0;
    while (getline(ss, token, '.')) {
        ipArray[i++] = stoi(token);
        
    }

}

//TODO output bitmap
int main() {

    string input1;
    string input2;
    //cout << "Enter start IP: ";
    //cin >> input1;
    //cout << "Enter end IP: ";
    //cin >> input2;

    //testing ips
    input1 = "192.168.0.1";
    input2 = "192.168.3.255";
    
    int iparr2[4];
    int iparr1[4];
    stringtoarray(input1, iparr1);
    stringtoarray(input2, iparr2);

    

    cout << ip_to_int(iparr1) << endl;
    cout << ip_to_int(iparr2) << endl;

    ips_array(ip_to_int(iparr1), ip_to_int(iparr2));

    return 0;
}