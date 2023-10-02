let submit_btn = document.querySelectorAll('.container input');
let list_div = document.getElementById('list-container');
let btn_div = document.getElementById('btn-cont')




submit_btn[1].addEventListener('click', () => {
    const data = submit_btn[0].value.trim(); // Trim any leading or trailing spaces
    if (data !== '') {
        const listItem = document.createElement('div');
        listItem.classList.add('list-item');
        listItem.setAttribute("onclick", "list_clicked(this)")

        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';

        const label = document.createElement('span'); // Use <span> instead of <label> for the text
        label.textContent = data;

        const pencilIcon = document.createElement('i');
        pencilIcon.classList.add('fas', 'fa-pencil'); // Correct the class name
        pencilIcon.setAttribute("onclick", "pencil(this)")

        const trashIcon = document.createElement('i');
        trashIcon.classList.add('fas', 'fa-trash');
        trashIcon.setAttribute("onclick", "delete_node(this)")

        listItem.appendChild(checkbox);
        listItem.appendChild(label);
        listItem.appendChild(pencilIcon); // Append the pencil icon
        listItem.appendChild(trashIcon);

        list_div.appendChild(listItem);

        submit_btn[0].value = ''; // Clear the input field

        list_div.removeAttribute('hidden');
    }
});

function list_clicked(element) {
    let div_list = element
    // console.log(div_list.textContent);
    const checkbox = div_list.querySelector('input[type="checkbox"]');
    if (checkbox.checked == false) {
        checkbox.checked = true;
    }
    else {
        checkbox.checked = false;
    }
}

// Add the event listener for the pencil icon click
function pencil(element) {
    const parentElement = element.parentElement;
    const spanElements = parentElement.getElementsByTagName('span');

    // Check if there's at least one span element
    if (spanElements.length > 0) {
        const span = spanElements[0]; // Access the first span element
        span.setAttribute('contenteditable', 'true');
    }
}

// delete one node 


function delete_node(element) {
    const parentElement = element.parentElement;
    parentElement.remove();
}

btn_div.getElementsByTagName('button')[0].addEventListener('click', () => {
    let whole_div_inner = list_div.querySelectorAll('.list-item')
    for (let index = 0; index < whole_div_inner.length; index++) {
        let checkbox = whole_div_inner[index].querySelector('input[type="checkbox"]')
        checkbox.checked = true;
    }
})


btn_div.getElementsByTagName('button')[1].addEventListener('click', () => {
    let whole_div_inner = list_div.querySelectorAll('.list-item')
    for (let index = 0; index < whole_div_inner.length; index++) {
        let check_checkbox=whole_div_inner[index].querySelector('input[type="checkbox"]')
        if(check_checkbox.checked===true){
            check_checkbox.parentElement.remove();
        }
    }
})

