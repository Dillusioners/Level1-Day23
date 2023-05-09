const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

// Define a Book class to represent books
class Book {
    constructor(title, author, ISBN, numCopies) {
        this.title = title;
        this.author = author;
        this.ISBN = ISBN;
        this.numCopies = numCopies;
    }

    // Getter method to get the availability of the book
    getAvailability() {
        if (this.numCopies === 0) {
            return "Out of stock";
        } else if (this.numCopies === 1) {
            return "Only 1 copy left";
        } else {
            return `${this.numCopies} copies available`;
        }
    }

    // Method to increase the number of copies of the book
    increaseCopies(num) {
        this.numCopies += num;
    }

    // Method to decrease the number of copies of the book
    decreaseCopies(num) {
        this.numCopies -= num;
    }
}

// Define a Library class to represent the library
class Library {
    constructor() {
        this.books = []; // Initialize an empty array to store books
    }

    // Method to add a new book to the library
    addBook(book) {
        this.books.push(book);
    }

    // Method to find a book by title
    findBookByTitle(title) {
        for (let i = 0; i < this.books.length; i++) {
            if (this.books[i].title.toLowerCase() === title.toLowerCase()) {
                return this.books[i];
            }
        }
        return null;
    }

    // Method to find a book by author
    findBookByAuthor(author) {
        const booksByAuthor = [];
        for (let i = 0; i < this.books.length; i++) {
            if (this.books[i].author.toLowerCase() === author.toLowerCase()) {
                booksByAuthor.push(this.books[i]);
            }
        }
        return booksByAuthor;
    }

    // Method to reserve a book
    reserveBook(title) {
        const book = this.findBookByTitle(title);
        if (book !== null && book.numCopies > 0) {
            book.decreaseCopies(1);
            console.log(`Book '${book.title}' reserved successfully. ${book.getAvailability()}`);
        } else if (book !== null && book.numCopies === 0) {
            console.log(`Sorry, book '${book.title}' is out of stock.`);
        } else {
            console.log(`Book '${title}' not found in the library.`);
        }
    }
}

// Create a library object
const library = new Library();

console.log("\n \n \nWelcome to the Dillusioners Library!\n"
    + "Please select an option:\n"
    + "1. Add a book\n"
    + "2. Find Book by Author\n"
    + "3. Find book by Title\n"
    + "4. Reserve a Book \n"
    + "5. Exit\n")

readline.question('Enter your choice=> ', choice => {
    if (choice == 1) {
        var name, author, isbn, copies;
        readline.question("Enter the name:-", get_name => {
            name = get_name;
            readline.close();
        })
        readline.question("Enter the author:-", get_author => {
            author = get_author;
            readline.close();
        })
        readline.question("Enter the ISBN:-", get_isbn => {
            isbn = get_isbn;
            readline.close();
        })
        readline.question("Enter the number of copies:-", get_copies => {
            copies = get_copies;
            readline.close();
        })
        library.addBook(new Book(name, author, isbn, copies));
        console.log(`Added ${copies} copy(s) of book named '${name}' by ${author} with ISBN Code '${isbn}'`)
    }
    else if (choice == 2) {
        var author;
        readline.question("Enter the author:-", get_author => {
            author = get_author;
            // Search for books by author
            const booksByauthor = library.findBookByAuthor(author);
            console.log(`Books by ${author}: ${booksByauthor.map(book => book.title).join(", ")}`);
        })
    }
    else if (choice == 3) {
        var title;
        readline.question("Enter the title of the book:-", get_title => {
            title = get_title;
            // Search for a book by title
            const book1 = library.findBookByTitle(title);
            console.log(`Book '${book1.title}' by ${book1.author}. ${book1.getAvailability()}`);
        })
    }
    else if (choice == 4) {
        var title;
        readline.question("Enter the title of the book:-", get_title => {
            title = get_title;
            // Reserve a book
            library.reserveBook(title);
        })
    }
    else {
        console.log("Enter anything above the following.");
    }
    readline.close();
});



// Add some demo books to the library
library.addBook(new Book("The Hobbit", "J.R.R. Tolkien", "9780547928227", 3));
library.addBook(new Book("To Kill a Mockingbird", "Harper Lee", "9780061120084", 2));
library.addBook(new Book("1984", "George Orwell", "9780141036144", 1));
