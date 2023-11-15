// Хранение продуктов
let products = [];

// Функция для обновления таблицы и суммарной стоимости
function updateTable() {
  const tableBody = document.getElementById("productList");
  const totalElement = document.getElementById("total");
  let total = 0;
  
  // Очищаем таблицу
  tableBody.innerHTML = "";
  
  // Добавляем каждый продукт в таблицу
  products.forEach((product, index) => {
    const row = document.createElement("tr");
    
    const nameCell = document.createElement("td");
    nameCell.textContent = product.name;
    row.appendChild(nameCell);
    
    const priceCell = document.createElement("td");
    priceCell.textContent = product.price;
    row.appendChild(priceCell);
    
    const quantityCell = document.createElement("td");
    quantityCell.textContent = product.quantity;
    row.appendChild(quantityCell);
    
    const actionsCell = document.createElement("td");
    
    // Кнопка удаления продукта
    const deleteButton = document.createElement("button");
    deleteButton.textContent = "Удалить";
    deleteButton.addEventListener("click", () => {
      products.splice(index, 1);
      updateTable();
    });
    actionsCell.appendChild(deleteButton);
    
    // Кнопка редактирования продукта
    const editButton = document.createElement("button");
    editButton.textContent = "Редактировать";
    editButton.addEventListener("click", () => {
      editProduct(index);
    });
    actionsCell.appendChild(editButton);
    
    row.appendChild(actionsCell);
    
    tableBody.appendChild(row);
    
    // Рассчитываем суммарную стоимость продуктов
    total += product.price * product.quantity;
  });
  
  // Обновляем суммарную стоимость
  totalElement.textContent = "Сумма: " + total;
}

// Функция для добавления продукта
function addProduct(name, price, quantity) {
  const product = {
    name: name,
    price: price,
    quantity: quantity
  };
  
  products.push(product);
  updateTable();
}

// Функция для редактирования продукта
function editProduct(index) {
  const product = products[index];
  
  // Заполняем форму данными продукта для редактирования
  document.getElementById("name").value = product.name;
  document.getElementById("price").value = product.price;
  document.getElementById("quantity").value = product.quantity;
  
  // Удаляем продукт из массива, чтобы избежать дублирования
  products.splice(index, 1);
  
  // Обновляем таблицу без редактируемого продукта
  updateTable();
}

// Обработчик события отправки формы
document.getElementById("productForm").addEventListener("submit", (e) => {
  e.preventDefault();
  
  const name = document.getElementById("name").value;
  const price = parseFloat(document.getElementById("price").value);
  const quantity = parseInt(document.getElementById("quantity").value);
  
  if (!isNaN(price) && !isNaN(quantity) && name.trim() !== "") {
    addProduct(name, price, quantity);
    
    // Сброс формы
    document.getElementById("name").value = "";
    document.getElementById("price").value = "";
    document.getElementById("quantity").value = "";
  }
});