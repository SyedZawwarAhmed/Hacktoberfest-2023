var app = angular.module("MyApp", []);
app.controller("MyController", function ($scope) {
    $scope.products = [];

    $scope.addProduct = function () {
        if ($scope.name != undefined && $scope.price) {
            let data = {
                name: $scope.name,
                price: $scope.price
            }
            $scope.products.push(data);
            $scope.name = ''; 
            $scope.price = '';
        }
        else {
            alert("Please enter the data..")
        }
    }

    $scope.remove = function (index) {
        $scope.products.splice(index, 1);
    }
});
