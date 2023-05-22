import java.util.*;

class GasCylinder {
    private int inventoryNumber; // Инвентарный номер газового баллона
    private double gasVolume; // Объем газа в баллоне
    private boolean canBeUsed; // Можно ли использовать газовый баллон

    public GasCylinder(int inventoryNumber, double gasVolume, boolean canBeUsed) {
        this.inventoryNumber = inventoryNumber;
        this.gasVolume = gasVolume;
        this.canBeUsed = canBeUsed;
    }

    public int getInventoryNumber() {
        return inventoryNumber;
    }

    public double getGasVolume() {
        return gasVolume;
    }

    public boolean canBeUsed() {
        return canBeUsed;
    }

    public void setGasVolume(double gasVolume) {
        this.gasVolume = gasVolume;
    }
}

class CylinderService {
    private static final double CYLINDER_CAPACITY = 100.0; // Максимальная емкость газового баллона

    private Queue<GasCylinder> inputQueue; // Очередь газовых баллонов для обработки
    private Stack<GasCylinder> repairedCylindersStack; // Стек отремонтированных газовых баллонов
    private Stack<GasCylinder> refillingCylindersStack; // Стек газовых баллонов, заполняющихся газом
    private Stack<GasCylinder> discardedCylindersStack; // Стек выброшенных газовых баллонов
    private Stack<GasCylinder> donorCylindersStack; // Стек газовых баллонов-доноров
    private Map<Integer, List<GasCylinder>> refilledCylindersMap; // Карта заполненных газовых баллонов

    public CylinderService(Queue<GasCylinder> inputQueue) {
        this.inputQueue = inputQueue;
        this.repairedCylindersStack = new Stack<>();
        this.refillingCylindersStack = new Stack<>();
        this.discardedCylindersStack = new Stack<>();
        this.donorCylindersStack = new Stack<>();
        this.refilledCylindersMap = new HashMap<>();
    }

    public void processCylinders() {
        // Обработка газовых баллонов в очереди
        while (!inputQueue.isEmpty()) {
            GasCylinder cylinder = inputQueue.dequeue();

            if (cylinder.canBeUsed()) {
                if (cylinder.getGasVolume() == CYLINDER_CAPACITY) {
                    repairedCylindersStack.push(cylinder); // Добавить полностью заполненный баллон в стек отремонтированных
                } else {
                    refillingCylindersStack.push(cylinder); // Добавить частично заполненный баллон в стек заполняющихся
                }
            } else {
                if (cylinder.getGasVolume() == 0.0) {
                    discardedCylindersStack.push(cylinder); // Добавить пустой баллон в стек выброшенных
                } else {
                    refillCylinders(cylinder); // Добавить частично использованный баллон в стек доноров и выполнить заполнение
                }
            }
        }

        // Обработка заполнения газовых баллонов из стека доноров и вывод статистики
        while (!donorCylindersStack.isEmpty() && !refillingCylindersStack.isEmpty()) {
            GasCylinder donorCylinder = donorCylindersStack.pop();
            GasCylinder refillingCylinder = refillingCylindersStack.pop();
            double remainingGas = CYLINDER_CAPACITY - refillingCylinder.getGasVolume();

            if (remainingGas <= donorCylinder.getGasVolume()) {
                refillingCylinder.setGasVolume(CYLINDER_CAPACITY);
                recordRefilledCylinder(refillingCylinder, donorCylinder, remainingGas);
                repairedCylindersStack.push(refillingCylinder);
            } else {
                refillingCylinder.setGasVolume(refillingCylinder.getGasVolume() + donorCylinder.getGasVolume());
                recordRefilledCylinder(refillingCylinder, donorCylinder, donorCylinder.getGasVolume());
                donorCylinder.setGasVolume(0.0);
                refillingCylindersStack.push(refillingCylinder);
            }
        }

        // Вывод статистики
        printStatistics();
    }

    private void refillCylinders(GasCylinder cylinder) {
        donorCylindersStack.push(cylinder);

        while (!donorCylindersStack.isEmpty() && !refillingCylindersStack.isEmpty()) {
            GasCylinder donorCylinder = donorCylindersStack.pop();
            GasCylinder refillingCylinder = refillingCylindersStack.pop();
            double remainingGas = CYLINDER_CAPACITY - refillingCylinder.getGasVolume();

            if (remainingGas <= donorCylinder.getGasVolume()) {
                refillingCylinder.setGasVolume(CYLINDER_CAPACITY);
                recordRefilledCylinder(refillingCylinder, donorCylinder, remainingGas);
                repairedCylindersStack.push(refillingCylinder);
            } else {
                refillingCylinder.setGasVolume(refillingCylinder.getGasVolume() + donorCylinder.getGasVolume());
                recordRefilledCylinder(refillingCylinder, donorCylinder, donorCylinder.getGasVolume());
                donorCylinder.setGasVolume(0.0);
                refillingCylindersStack.push(refillingCylinder);
            }
        }
    }

    private void recordRefilledCylinder(GasCylinder refillingCylinder, GasCylinder donorCylinder, double refilledVolume) {
        int inventoryNumber = refillingCylinder.getInventoryNumber();
        List<GasCylinder> refilledCylinders = refilledCylindersMap.getOrDefault(inventoryNumber, new ArrayList<>());
        refilledCylinders.add(donorCylinder);
        refilledCylindersMap.put(inventoryNumber, refilledCylinders);
    }

    private void printStatistics() {
        System.out.println("Статистика для заполненных баллонов:");
        for (Map.Entry<Integer, List<GasCylinder>> entry : refilledCylindersMap.entrySet()) {
            int inventoryNumber = entry.getKey();
            List<GasCylinder> refilledCylinders = entry.getValue();
            System.out.println("Инвентарный номер: " + inventoryNumber);
            System.out.println("Количество заполнений: " + refilledCylinders.size());
            for (GasCylinder cylinder : refilledCylinders) {
                System.out.println("Объем заполнения: " + cylinder.getGasVolume() + ", Заполнено из: " + cylinder.getInventoryNumber());
            }
            System.out.println();
        }

        System.out.println("Статистика для частично заполненных баллонов:");
        while (!refillingCylindersStack.isEmpty()) {
            GasCylinder cylinder = refillingCylindersStack.pop();
            System.out.println("Инвентарный номер: " + cylinder.getInventoryNumber());
            System.out.println("Оставшийся объем: " + cylinder.getGasVolume());
            System.out.println();
        }

        System.out.println("Выброшенные баллоны:");
        while (!discardedCylindersStack.isEmpty()) {
            GasCylinder cylinder = discardedCylindersStack.pop();
            System.out.println("Инвентарный номер: " + cylinder.getInventoryNumber());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Queue<GasCylinder> inputQueue = new Queue<>(4);

        // Добавление информации о газовых баллонах во входную очередь
        inputQueue.enqueue(new GasCylinder(1, 75.0, true));
        inputQueue.enqueue(new GasCylinder(2, 100.0, true));
        inputQueue.enqueue(new GasCylinder(3, 50.0, false));
        inputQueue.enqueue(new GasCylinder(4, 0.0, false));

        CylinderService cylinderService = new CylinderService(inputQueue);
        cylinderService.processCylinders();
    }
}