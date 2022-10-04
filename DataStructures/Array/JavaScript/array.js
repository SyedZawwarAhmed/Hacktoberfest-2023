"use strict"

const arr = [1, 4, -12, 7, 91]

// Traversal
arr.forEach(el => console.log(el))

// push
arr.push(23) // [1, 4, -12, 7, 91, 23]

// pop
arr.pop() // [1, 4, -12, 7, 91]

// unshift
arr.unshift(12) // [12, 1, 4, -12, 7, 91]

// shift
arr.shift() // [1, 4, -12, 7, 91]

// map
const doubleArr = arr.map(el => 2 * el)
console.log(doubleArr) // [ 2, 8, -24, 14, 182 ]

// filter
const evenArr = arr.filter(el => el % 2 === 0)
console.log(evenArr) // [ 4, -12 ]

// reduce
const sum = arr.reduce((acc, el) => acc + el, 0)
console.log(sum)