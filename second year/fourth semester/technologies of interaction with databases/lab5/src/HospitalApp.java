import java.sql.*;
import java.util.Scanner;

public class HospitalApp {
    private static final String DB_URL = "jdbc:postgresql://localhost:5432/hospital_db";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = " ";

    public static void main(String[] args) {
        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            System.out.println("Connected to the database.");

            // Вывод результатов SQL-запросов из предыдущих лабораторных работ
            executeQuery(connection, "SELECT t.id, t.patient_name, t.date, t.start_time, t.duration, " +
                    "d.first_name, d.last_name, s.name AS specialty_name " +
                    "FROM tickets t " +
                    "INNER JOIN doctors d ON d.id = t.doctor_id " +
                    "INNER JOIN specialties s ON s.id = d.specialty_id");

            executeQuery(connection, "SELECT s.name AS specialty_name, COUNT(d.id) AS num_doctors " +
                    "FROM specialties s " +
                    "LEFT JOIN doctors d ON d.specialty_id = s.id " +
                    "GROUP BY s.name");

            executeQuery(connection, "SELECT s.name AS specialty_name, SUM(s.duration) AS total_duration " +
                    "FROM specialties s " +
                    "LEFT JOIN doctors d ON d.specialty_id = s.id " +
                    "GROUP BY s.name");

            executeQuery(connection, "SELECT d.first_name, d.last_name, COUNT(t.id) AS num_tickets " +
                    "FROM doctors d " +
                    "LEFT JOIN tickets t ON t.doctor_id = d.id " +
                    "GROUP BY d.id");

            // Взаимодействие с пользователем
            Scanner scanner = new Scanner(System.in);
            boolean exit = false;

            while (!exit) {
                System.out.println();
                System.out.println("Выберите действие:");
                System.out.println("1. Добавить запись");
                System.out.println("2. Редактировать запись");
                System.out.println("3. Удалить запись");
                System.out.println("4. Выйти из приложения");
                System.out.print("Введите номер действия: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Считываем символ новой строки

                switch (choice) {
                    case 1:
                        addRecord(connection, scanner);
                        break;
                    case 2:
                        editRecord(connection, scanner);
                        break;
                    case 3:
                        deleteRecord(connection, scanner);
                        break;
                    case 4:
                        exit = true;
                        break;
                    default:
                        System.out.println("Неверный номер действия. Попробуйте снова.");
                }
            }

            System.out.println("Завершение работы приложения.");
        } catch (SQLException e) {
            System.err.println("Ошибка при работе с базой данных: " + e.getMessage());
        }
    }

    private static void executeQuery(Connection connection, String sqlQuery) throws SQLException {
        try (Statement statement = connection.createStatement()) {
            ResultSet resultSet = statement.executeQuery(sqlQuery);
            ResultSetMetaData metaData = resultSet.getMetaData();
            int columnCount = metaData.getColumnCount();

            System.out.println("Результат запроса:");
            System.out.println();

            // Вывод заголовков столбцов
            for (int i = 1; i <= columnCount; i++) {
                System.out.printf("%-20s", metaData.getColumnName(i));
            }
            System.out.println();

            // Вывод результатов запроса
            while (resultSet.next()) {
                for (int i = 1; i <= columnCount; i++) {
                    System.out.printf("%-20s", resultSet.getString(i));
                }
                System.out.println();
            }

            System.out.println();
        }
    }

    private static void addRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.println("Выберите таблицу для добавления записи:");
        System.out.println("1. specialties");
        System.out.println("2. doctors");
        System.out.println("3. tickets");
        System.out.print("Введите номер таблицы: ");
        int tableChoice = scanner.nextInt();
        scanner.nextLine(); // Считываем символ новой строки

        String tableName;
        String[] columns;
        String[] values;

        switch (tableChoice) {
            case 1:
                tableName = "specialties";
                columns = new String[]{"name", "duration"};
                values = new String[2];

                System.out.print("Введите название специальности: ");
                values[0] = scanner.nextLine();

                System.out.print("Введите длительность работы специальности (например, '6 months'): ");
                values[1] = scanner.nextLine();
                break;
            case 2:
                tableName = "doctors";
                columns = new String[]{"first_name", "last_name", "middle_name", "specialty_id", "district_number", "phone_numbers"};
                values = new String[6];

                System.out.print("Введите имя врача: ");
                values[0] = scanner.nextLine();

                System.out.print("Введите фамилию врача: ");
                values[1] = scanner.nextLine();

                System.out.print("Введите отчество врача (если есть, иначе нажмите Enter): ");
                values[2] = scanner.nextLine();

                System.out.print("Введите идентификатор специальности врача: ");
                values[3] = scanner.nextLine();

                System.out.print("Введите номер района работы врача: ");
                values[4] = scanner.nextLine();

                System.out.print("Введите номера телефонов врача через запятую: ");
                values[5] = scanner.nextLine();
                break;
            case 3:
                tableName = "tickets";
                columns = new String[]{"doctor_id", "date", "start_time", "duration", "patient_name"};
                values = new String[5];

                System.out.print("Введите идентификатор врача: ");
                values[0] = scanner.nextLine();

                System.out.print("Введите дату талона на прием в формате 'YYYY-MM-DD': ");
                values[1] = scanner.nextLine();

                System.out.print("Введите время начала талона на прием в формате 'HH:MM:SS': ");
                values[2] = scanner.nextLine();

                System.out.print("Введите длительность талона на прием (например, '1 hour' или '30 minutes'): ");
                values[3] = scanner.nextLine();

                System.out.print("Введите имя пациента (если есть, иначе нажмите Enter): ");
                values[4] = scanner.nextLine();
                break;
            default:
                System.out.println("Неверный номер таблицы.");
                return;
        }

        String sqlQuery = generateInsertQuery(tableName, columns);
        try (PreparedStatement statement = connection.prepareStatement(sqlQuery)) {
            for (int i = 0; i < values.length; i++) {
                statement.setString(i + 1, values[i]);
            }

            int affectedRows = statement.executeUpdate();
            System.out.println("Запись успешно добавлена. Количество измененных строк: " + affectedRows);
        }
    }

    private static String generateInsertQuery(String tableName, String[] columns) {
        StringBuilder queryBuilder = new StringBuilder();
        queryBuilder.append("INSERT INTO ").append(tableName).append(" (");

        for (int i = 0; i < columns.length; i++) {
            queryBuilder.append(columns[i]);
            if (i < columns.length - 1) {
                queryBuilder.append(", ");
            }
        }

        queryBuilder.append(") VALUES (");

        for (int i = 0; i < columns.length; i++) {
            queryBuilder.append("?");
            if (i < columns.length - 1) {
                queryBuilder.append(", ");
            }
        }

        queryBuilder.append(")");

        return queryBuilder.toString();
    }

    private static void editRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.println("Выберите таблицу для редактирования записи:");
        System.out.println("1. specialties");
        System.out.println("2. doctors");
        System.out.println("3. tickets");
        System.out.print("Введите номер таблицы: ");
        int tableChoice = scanner.nextInt();
        scanner.nextLine(); // Считываем символ новой строки

        String tableName;
        String primaryKeyColumn;
        String primaryKeyValue;

        switch (tableChoice) {
            case 1:
                tableName = "specialties";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор специальности для редактирования: ");
                primaryKeyValue = scanner.nextLine();
                break;
            case 2:
                tableName = "doctors";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор врача для редактирования: ");
                primaryKeyValue = scanner.nextLine();
                break;
            case 3:
                tableName = "tickets";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор талона на прием для редактирования: ");
                primaryKeyValue = scanner.nextLine();
                break;
            default:
                System.out.println("Неверный номер таблицы.");
                return;
        }

        String sqlQuery = generateSelectQuery(tableName, primaryKeyColumn);
        try (PreparedStatement statement = connection.prepareStatement(sqlQuery)) {
            statement.setString(1, primaryKeyValue);

            ResultSet resultSet = statement.executeQuery();
            ResultSetMetaData metaData = resultSet.getMetaData();
            int columnCount = metaData.getColumnCount();

            if (resultSet.next()) {
                System.out.println("Текущие значения записи:");

                for (int i = 1; i <= columnCount; i++) {
                    System.out.printf("%-20s%-20s\n", metaData.getColumnName(i), resultSet.getString(i));
                }

                System.out.println();
                System.out.println("Введите новые значения записи:");

                String[] columns = new String[columnCount - 1];
                String[] values = new String[columnCount - 1];

                for (int i = 1; i <= columnCount - 1; i++) {
                    columns[i - 1] = metaData.getColumnName(i + 1);
                    System.out.printf("%s: ", columns[i - 1]);
                    values[i - 1] = scanner.nextLine();
                }

                String updateQuery = generateUpdateQuery(tableName, columns, primaryKeyColumn);
                try (PreparedStatement updateStatement = connection.prepareStatement(updateQuery)) {
                    for (int i = 0; i < values.length; i++) {
                        updateStatement.setString(i + 1, values[i]);
                    }
                    updateStatement.setString(values.length + 1, primaryKeyValue);

                    int affectedRows = updateStatement.executeUpdate();
                    System.out.println("Запись успешно отредактирована. Количество измененных строк: " + affectedRows);
                }
            } else {
                System.out.println("Запись с указанным идентификатором не найдена.");
            }
        }
    }

    private static String generateSelectQuery(String tableName, String primaryKeyColumn) {
        return "SELECT * FROM " + tableName + " WHERE " + primaryKeyColumn + " = ?";
    }

    private static String generateUpdateQuery(String tableName, String[] columns, String primaryKeyColumn) {
        StringBuilder queryBuilder = new StringBuilder();
        queryBuilder.append("UPDATE ").append(tableName).append(" SET ");

        for (int i = 0; i < columns.length; i++) {
            queryBuilder.append(columns[i]).append(" = ?");
            if (i < columns.length - 1) {
                queryBuilder.append(", ");
            }
        }

        queryBuilder.append(" WHERE ").append(primaryKeyColumn).append(" = ?");

        return queryBuilder.toString();
    }

    private static void deleteRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.println("Выберите таблицу для удаления записи:");
        System.out.println("1. specialties");
        System.out.println("2. doctors");
        System.out.println("3. tickets");
        System.out.print("Введите номер таблицы: ");
        int tableChoice = scanner.nextInt();
        scanner.nextLine(); // Считываем символ новой строки

        String tableName;
        String primaryKeyColumn;
        String primaryKeyValue;

        switch (tableChoice) {
            case 1:
                tableName = "specialties";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор специальности для удаления: ");
                primaryKeyValue = scanner.nextLine();
                break;
            case 2:
                tableName = "doctors";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор врача для удаления: ");
                primaryKeyValue = scanner.nextLine();
                break;
            case 3:
                tableName = "tickets";
                primaryKeyColumn = "id";

                System.out.print("Введите идентификатор талона на прием для удаления: ");
                primaryKeyValue = scanner.nextLine();
                break;
            default:
                System.out.println("Неверный номер таблицы.");
                return;
        }

        String deleteQuery = generateDeleteQuery(tableName, primaryKeyColumn);
        try (PreparedStatement statement = connection.prepareStatement(deleteQuery)) {
            statement.setString(1, primaryKeyValue);

            int affectedRows = statement.executeUpdate();
            System.out.println("Запись успешно удалена. Количество измененных строк: " + affectedRows);
        }
    }

    private static String generateDeleteQuery(String tableName, String primaryKeyColumn) {
        return "DELETE FROM " + tableName + " WHERE " + primaryKeyColumn + " = ?";
    }
}