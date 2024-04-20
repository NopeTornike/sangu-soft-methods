#include <iostream>
#include <fstream>
#include <string>

/**
 * @file Logger.h
 * @brief Logger class used for logging messages to console and to a file.
 */

class Logger {
public:
    /**
     * Logs a message to the console.
     * @param message The message to log; must not be empty or contain invalid characters.
     * @throw std::invalid_argument If the message is empty or contains invalid characters.
     */
    static void Log(const std::string& message) {
        Validate(message);
        std::cout << message << std::endl;
    }

    /**
     * Logs a message to a file named "filename.txt".
     * @param message The message to log; must not be empty or contain invalid characters.
     * @throw std::runtime_error If the file cannot be opened.
     * @throw std::invalid_argument If the message is empty or contains invalid characters.
     */
    static void LogToFile(const std::string& message) {
        std::ofstream file("filename.txt");
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file.");
        }
        file << message;
        file.close();
    }

private:
    /**
     * Validates a message to ensure it is not empty and does not contain invalid characters.
     * @param message The message to validate.
     * @throw std::invalid_argument If the message is empty or contains invalid characters.
     */
    static void Validate(const std::string& message) {
        if (message.empty()) {
            throw std::invalid_argument("Message is empty.");
        }
        for (char c : message) {
            if (!isalpha(c) && c != ' ') {
                throw std::invalid_argument("Message contains invalid symbols.");
            }
        }
    }
};
