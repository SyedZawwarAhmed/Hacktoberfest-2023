const todoInput = document.querySelector("#to_do");
const todoButton = document.querySelector("#submit");
const todoList = document.querySelector("#list_area");

// event litseners 
document.addEventListener("DOMContentLoaded", getTodos);
todoButton.addEventListener("click", addtodo);
todoList.addEventListener("click", deleteTodo);


//function
function addtodo(e){

    //Create todo div
    const todoDiv = document.createElement("div");
    todoDiv.classList.add("list_area");

    //Create list

    const newTodo = document.createElement("li");
    newTodo.innerText = todoInput.value;
    todoDiv.appendChild(newTodo);
    
    
   //calling thew save function
    saveLocalTodos(todoInput.value);


    //resting the value  to null
    todoInput.value = "";


    //Create Completed Button
    const completedButton = document.createElement("button");
    completedButton.innerHTML = `<i class="bi bi-check"></i>`;
    completedButton.classList.add("complete-btn");

    todoDiv.appendChild(completedButton);


    //Create trash button
    const trashButton = document.createElement("button");
    trashButton.innerHTML = `<i class="bi bi-trash"></i>`;
    trashButton.classList.add("trash-btn");
    todoDiv.appendChild(trashButton);

    //adding the div to the unordered list
    todoList.appendChild(todoDiv);
} ;


function deleteTodo(e) {
    const item = e.target;
  
    if (item.classList[0] === "trash-btn") {
    
      const todo = item.parentElement;
      // add the animation
      todo.classList.add("drop");
      removeLocalTodos(todo);
      todo.addEventListener("transitionend", e => {
        //removes the div after the animation is completed
        todo.remove();
      });
    }
    if (item.classList[0] === "complete-btn") {
      const todo = item.parentElement;
      
      // switches class when clicked to show complete and incomplete satus
      todo.classList.toggle("completed");
      console.log(todo);
    }
  }

  
function saveLocalTodos(todoitem) {
    let todos;
    if (localStorage.getItem("todos") === null) {
      todos = [];
    } else {
      todos = JSON.parse(localStorage.getItem("todos"));
    }
    todos.push(todoitem);
    localStorage.setItem("todos", JSON.stringify(todos));
  }


  function removeLocalTodos(todoitem) {
    let todos;
    if (localStorage.getItem("todos") === null) {
      todos = [];
    } else {
      todos = JSON.parse(localStorage.getItem("todos"));
    }
    const todoIndex = todoitem.children[0].innerText;
    todos.splice(todos.indexOf(todoIndex), 1);
    localStorage.setItem("todos", JSON.stringify(todos));
  }
  
  function getTodos() {
    let todos;
    if (localStorage.getItem("todos") === null) {
      todos = [];
    } else {
      todos = JSON.parse(localStorage.getItem("todos"));
    }
    todos.forEach(function(todoitem) {
      //Create todo div
      const todoDiv = document.createElement("div");
      todoDiv.classList.add("list_area");
      
      //Create list
      const newTodo = document.createElement("li");
      newTodo.innerText = todoitem;
      
      todoDiv.appendChild(newTodo);
      todoInput.value = "";
     
    //Create Completed Button
    const completedButton = document.createElement("button");
    completedButton.innerHTML = `<i class="bi bi-check"></i>`;
    completedButton.classList.add("complete-btn");

    todoDiv.appendChild(completedButton);


    //Create trash button
    const trashButton = document.createElement("button");
    trashButton.innerHTML = `<i class="bi bi-trash"></i>`;
    trashButton.classList.add("trash-btn");
    todoDiv.appendChild(trashButton);


      //attach final Todo
      todoList.appendChild(todoDiv);
    });
  }