# Cargo Loading Optimizer using Fractional Knapsack

**Problem Statement:** 14
**Module:** Module 3 – Greedy Method Approach
**Algorithm:** Fractional Knapsack
**Language:** C

## Problem Statement

Build a program that selects full or fractional cargo items to maximize value within a vehicle's weight capacity.

Each cargo item has a weight and profit. Items are arranged according to their profit-to-weight ratio and are loaded greedily until the vehicle capacity is reached.

## Algorithm

1. Accept the number of items and vehicle capacity.
2. Enter the weight and profit of each item.
3. Calculate the profit-to-weight ratio.
4. Sort the items in decreasing order of ratio.
5. Select complete items whenever possible.
6. If the remaining capacity is insufficient, select a fraction of the next item.
7. Calculate the maximum total profit.
8. Display the loading plan.

## Example

For a vehicle capacity of 50 kg:

| Item | Weight | Profit |
| ---- | ------ | ------ |
| 1    | 10 kg  | 60     |
| 2    | 20 kg  | 100    |
| 3    | 30 kg  | 120    |

The maximum profit obtained is **240**.

## Files

* `Cargo.cpp` – C implementation of the Fractional Knapsack algorithm.

## Concepts Used

* Greedy Algorithm
* Fractional Knapsack
* Sorting
* Profit-to-weight ratio
* Structures in C
* Algorithm Analysis

