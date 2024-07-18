# Plazza - Concurrent Programming Project

## Overview

Plazza is a simulation of a pizzeria designed for concurrent programming practice. It consists of a reception handling pizza orders, kitchens managed as child processes, and cooks operating within threads. The project emphasizes process synchronization, load balancing, and inter-process communication.

## Project Parameters

- **Multiplier:** Adjusts pizza cooking times for easier program evaluation.
- **Cooks per Kitchen:** Number of cooks per kitchen.
- **Ingredient Restocking Time:** Time interval for restocking kitchen ingredients.

## Features

- **Interactive Reception:** Command-line shell for placing pizza orders and checking kitchen statuses.
- **Grammar-Based Ordering:** Orders are parsed based on a defined grammar (`TYPE SIZE NUMBER`).
- **Dynamic Kitchen Management:** Kitchens are created as needed to manage incoming orders.
- **Load Balancing:** Orders are distributed among kitchens to balance workload.
- **IPC Communication:** Inter-process communication ensures seamless coordination between reception and kitchens.

## Implementation Details

- **Processes:** Kitchens are managed as child processes of the reception.
- **Threads:** Each cook within a kitchen is represented as a thread.
- **Mutex and Conditional Variables:** Used for thread synchronization and managing shared resources.
- **IPC Mechanism:** Chosen and encapsulated for efficient data exchange between processes.
- **Error Handling:** Error messages are sent to stderr, exiting with appropriate error codes.

## Pizzas

Supported Pizza Types:
- **Margarita:** Dough, tomato, gruyere.
- **Regina:** Dough, tomato, gruyere, ham, mushrooms.
- **Americana:** Dough, tomato, gruyere, steak.
- **Fantasia:** Dough, tomato, eggplant, goat cheese.

Each pizza type has specific ingredients and baking times adjusted by the multiplier parameter.

## Additional Features

- **Graphical Interface (Bonus):** Optional graphical version of the reception for enhanced user experience.
- **Logging:** Records orders and kitchen activities for monitoring and troubleshooting.

## Usage

### Starting Plazza

```bash
./plazza <multiplier> <cooks_per_kitchen> <restock_time>
```

- `<multiplier>`: Adjusts pizza cooking times.
- `<cooks_per_kitchen>`: Number of cooks per kitchen.
- `<restock_time>`: Ingredient restocking time in milliseconds.

### Commands

- **Ordering Pizza:** `TYPE SIZE NUMBER [; TYPE SIZE NUMBER ]*`
  Example: `regina XXL x2; fantasia M x3; margarita S x1`

- **Display Kitchen Status:** `status`
  Shows current kitchen occupancy and ingredient stocks.

## Bonus Directory

Contains additional files like a graphical reception interface if implemented.

## Error Handling

- Exits with code 84 for errors, 0 if no error.

## Notes

- Ensure all source files (excluding binaries and temp files) are included in the delivery.
- Use Makefile for compilation with `re`, `clean`, and `fclean` rules.

## Authors

- Matthis Brocheton
