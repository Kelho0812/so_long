# get_next_line

## Overview

`get_next_line` is a function that reads a line from a file descriptor. This project is part of the Common Core curriculum at 42 Porto school.

## Table of Contents

- [Function Description](#function-description)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Function Description

The `get_next_line` function is used as follows:

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.

The function returns a newly allocated string containing the line read, or `NULL` if the end of the file has been reached or an error occurred.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/Kelho0812/get_next_line.git
cd get_next_line
```

2. Build the project:

```bash
make
```

## Usage

To use `get_next_line`, include the `get_next_line.h` header file in your project. Call the function with the file descriptor as the argument to retrieve a line.

Example:

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        // Do something with the line
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return (0);
}
```

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

---
