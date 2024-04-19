const fs = require('fs');

class Logger {
    static log(message) {
        this.validate(message);
        console.log(message);
    }

    static logToFile(message) {
        fs.writeFile('filename.txt', message, { flag: 'a' }, (err) => {
            if (err) {
                throw new Error('Failed to open file.');
            }
        });
    }

    static validate(message) {
        if (message === null) {
            throw new Error('Message cannot be null.');
        }
        if (message.trim() === '') {
            throw new Error('Message cannot be empty.');
        }
    }
}

try {
    Logger.log("Hi, I am Tornike");
    Logger.logToFile("Hi, I am Tornike");
    Logger.log("");  
    Logger.log(null);  
} catch (e) {
    console.error("Exception:", e.message);
}