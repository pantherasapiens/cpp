#include <iostream>
#include <string>
using namespace std;

// Function to perform CRC encoding
string crcEncode(const string& data, const string& generator) {
    string encodedData = data;
    int genLen = generator.length();

    // Append zeros to the data for the CRC bits
    encodedData += string(genLen - 1, '0');

    for (int i = 0; i < data.length(); i++) {
        if (encodedData[i] == '1') {
            for (int j = 0; j < genLen; j++) {
                encodedData[i + j] = (encodedData[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Extract and append the CRC bits to the data
    string crc = encodedData.substr(data.length());
    encodedData += crc;

    return encodedData;
}

// Function to check for errors using CRC
bool crcCheck(const string& receivedData, const string& generator) {
    string data = receivedData;
    int genLen = generator.length();

    for (int i = 0; i < data.length() - genLen + 1; i++) {
        if (data[i] == '1') {
            for (int j = 0; j < genLen; j++) {
                data[i + j] = (data[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // If there are any '1's left, an error is detected
    return (data.find('1') == string::npos);
}

int main() {
    string data = "11011010101101";
    string generator = "1011";

    string encodedData = crcEncode(data, generator);
    cout << "Encoded Data: " << encodedData << endl;

    // Simulate transmission with a possible error
    string receivedData = "11011010101101"; // Simulated received data
    bool hasError = crcCheck(receivedData, generator);
    
    if (hasError) {
        cout << "Error detected in the received data." << endl;
    } else {
        cout << "No error detected in the received data." << endl;
    }

    return 0;
}

