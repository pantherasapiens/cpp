#include <iostream>
#include <string>

// Function to encode data using Hamming code
std::string encodeHamming(const std::string& data) {
    int m = data.length();
    int r = 0;
    while ((1 << r) < m + r + 1) {
        r++;
    }

    std::string encodedData(m + r, '0');
    int j = 0;

    for (int i = 1; i <= m + r; i++) {
        if ((i & (i - 1)) != 0) {
            encodedData[i - 1] = data[j++];
        }
    }

    for (int i = 0; i < r; i++) {
        int pos = (1 << i) - 1;
        int parity = 0;
        for (int j = pos; j < m + r; j += (1 << (i + 1))) {
            parity ^= (encodedData[j] - '0');
        }
        encodedData[pos] = (parity + '0');
    }

    return encodedData;
}

// Function to decode data using Hamming code
std::string decodeHamming(const std::string& encodedData) {
    int m = encodedData.length();
    int r = 0;
    while ((1 << r) < m + r + 1) {
        r++;
    }

    std::string decodedData(encodedData);

    for (int i = 0; i < r; i++) {
        int pos = (1 << i) - 1;
        int parity = 0;
        for (int j = pos; j < m; j += (1 << (i + 1))) {
            parity ^= (decodedData[j] - '0');
        }
        if (parity != 0) {
            pos = (1 << i) - 1;
            decodedData[pos] = ((decodedData[pos] - '0') ^ 1) + '0';
        }
    }

    return decodedData;
}

int main() {
    std::string data = "1011001";

    std::string encodedData = encodeHamming(data);
    std::cout << "Encoded Data: " << encodedData << std::endl;

    // Simulate transmission with a possible error
    std::string receivedData = "1111001"; // Simulated received data with an error

    std::string decodedData = decodeHamming(receivedData);
    std::cout << "Decoded Data: " << decodedData << std::endl;

    return 0;
}

