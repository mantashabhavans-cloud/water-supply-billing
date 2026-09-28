document.addEventListener("DOMContentLoaded", function () {

    const billingForm = document.getElementById("billingForm");
    const resetButton = document.getElementById("resetButton");

    billingForm.addEventListener("submit", function (event) {

        event.preventDefault();

        const customerId =
            document.getElementById("customerId").value;

        const customerName =
            document.getElementById("customerName").value;

        const customerType =
            document.getElementById("customerType").value;

        const consumption =
            parseFloat(document.getElementById("consumption").value);

        if (customerId === "" ||
            customerName === "" ||
            customerType === "" ||
            isNaN(consumption) ||
            consumption < 0) {

            alert("Please enter all details correctly.");
            return;
        }

        let bill = 0;

        if (customerType === "domestic") {

            if (consumption <= 15) {
                bill = consumption * 5;
            }
            else if (consumption <= 30) {
                bill = (15 * 5) +
                       ((consumption - 15) * 7);
            }
            else {
                bill = (15 * 5) +
                       (15 * 7) +
                       ((consumption - 30) * 10);
            }

        }
        else if (customerType === "commercial") {

            if (consumption <= 20) {
                bill = consumption * 10;
            }
            else if (consumption <= 50) {
                bill = (20 * 10) +
                       ((consumption - 20) * 12);
            }
            else {
                bill = (20 * 10) +
                       (30 * 12) +
                       ((consumption - 50) * 15);
            }
        }

        document.getElementById("resultId").textContent =
            customerId;

        document.getElementById("resultName").textContent =
            customerName;

        document.getElementById("resultType").textContent =
            customerType === "domestic"
            ? "Domestic"
            : "Commercial";

        document.getElementById("resultConsumption").textContent =
            consumption + " units";

        document.getElementById("resultBill").textContent =
            bill.toFixed(2);
    });


    resetButton.addEventListener("click", function () {

        billingForm.reset();

        document.getElementById("resultId").textContent = "-";
        document.getElementById("resultName").textContent = "-";
        document.getElementById("resultType").textContent = "-";
        document.getElementById("resultConsumption").textContent = "-";
        document.getElementById("resultBill").textContent = "0.00";

    });

});
