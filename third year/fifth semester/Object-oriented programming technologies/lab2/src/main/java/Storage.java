import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;

import pckg.TelephoneOperator;

public class Storage {
    private static String jdbcUrl = null;
    private static String jdbcUser = null;
    private static String jdbcPassword = null;

    public static void init(String jdbcDriver, String jdbcUrl, String jdbcUser, String jdbcPassword) throws ClassNotFoundException {
        Class.forName(jdbcDriver);
        Storage.jdbcUrl = jdbcUrl;
        Storage.jdbcUser = jdbcUser;
        Storage.jdbcPassword = jdbcPassword;
    }

    public static Collection<TelephoneOperator> readAll() throws SQLException {
        String sql = "SELECT `ID`, `callerNumber`, `calledNumber`, `date`, `time`, `duration`, `costOneTariffUnit`, `billingUnit`, `costCall` FROM `TelephoneOperator`";
        Connection c = null;
        PreparedStatement s = null;
        ResultSet r = null;
        try {
            c = getConnection();
            s = c.prepareStatement(sql);
            r = s.executeQuery();
            Collection<TelephoneOperator> operators = new ArrayList<>();
            while (r.next()) {
                TelephoneOperator operator = new TelephoneOperator();
                operator.setID(r.getInt("ID"));
                operator.setCallerNumber(r.getInt("callerNumber"));
                operator.setCalledNumber(r.getInt("calledNumber"));
                operator.setDate(r.getString("date"));
                operator.setTime(r.getString("time"));
                operator.setDuration(r.getInt("duration"));
                operator.setCostOneTariffUnit(r.getInt("costOneTariffUnit"));
                operator.setBillingUnit(r.getInt("billingUnit"));
                operator.setCostCall(r.getInt("costCall"));
                operators.add(operator);
            }
            return operators;
        } finally {
            try {
                r.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                s.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                c.close();
            } catch (NullPointerException | SQLException e) {
            }
        }
    }

    public static TelephoneOperator readById(Integer id) throws SQLException {
        String sql = "SELECT `callerNumber`, `calledNumber`, `date`, `time`, `duration`, `costOneTariffUnit`, `billingUnit`, `costCall` FROM `TelephoneOperator` WHERE `ID` = ?";
        Connection c = null;
        PreparedStatement s = null;
        ResultSet r = null;
        try {
            c = getConnection();
            s = c.prepareStatement(sql);
            s.setInt(1, id);
            r = s.executeQuery();
            TelephoneOperator operator = null;
            if (r.next()) {
                operator = new TelephoneOperator();
                operator.setID(id);
                operator.setCallerNumber(r.getInt("callerNumber"));
                operator.setCalledNumber(r.getInt("calledNumber"));
                operator.setDate(r.getString("date"));
                operator.setTime(r.getString("time"));
                operator.setDuration(r.getInt("duration"));
                operator.setCostOneTariffUnit(r.getInt("costOneTariffUnit"));
                operator.setBillingUnit(r.getInt("billingUnit"));
                operator.setCostCall(r.getInt("costCall"));
            }
            return operator;
        } finally {
            try {
                r.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                s.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                c.close();
            } catch (NullPointerException | SQLException e) {
            }
        }
    }

    public static void create(TelephoneOperator operator) throws SQLException {
        String sql = "INSERT INTO `TelephoneOperator` (`callerNumber`, `calledNumber`, `date`, `time`, `duration`, `costOneTariffUnit`, `billingUnit`, `costCall`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
        Connection c = null;
        PreparedStatement s = null;
        try {
            c = getConnection();
            s = c.prepareStatement(sql);
            s.setInt(1, operator.getCallerNumber());
            s.setInt(2, operator.getCalledNumber());
            s.setString(3, operator.getDate());
            s.setString(4, operator.getTime());
            s.setInt(5, operator.getDuration());
            s.setInt(6, operator.getCostOneTariffUnit());
            s.setInt(7, operator.getBillingUnit());
            s.setInt(8, operator.getCostCall());
            s.executeUpdate();
        } finally {
            try {
                s.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                c.close();
            } catch (NullPointerException | SQLException e) {
            }
        }
    }

    public static void update(TelephoneOperator operator) throws SQLException {
        String sql = "UPDATE `TelephoneOperator` SET `callerNumber` = ?, `calledNumber` = ?, `date` = ?, `time` = ?, `duration` = ?, `costOneTariffUnit` = ?, `billingUnit` = ?, `costCall` = ? WHERE `ID` = ?";
        Connection c = null;
        PreparedStatement s = null;
        try {
            c = getConnection();
            s = c.prepareStatement(sql);
            s.setInt(1, operator.getCallerNumber());
            s.setInt(2, operator.getCalledNumber());
            s.setString(3, operator.getDate());
            s.setString(4, operator.getTime());
            s.setInt(5, operator.getDuration());
            s.setInt(6, operator.getCostOneTariffUnit());
            s.setInt(7, operator.getBillingUnit());
            s.setInt(8, operator.getCostCall());
            s.setInt(9, operator.getID());
            s.executeUpdate();
        } finally {
            try {
                s.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                c.close();
            } catch (NullPointerException | SQLException e) {
            }
        }
    }

    public static void delete(Integer id) throws SQLException {
        String sql = "DELETE FROM `TelephoneOperator` WHERE `ID` = ?";
        Connection c = null;
        PreparedStatement s = null;
        try {
            c = getConnection();
            s = c.prepareStatement(sql);
            s.setInt(1, id);
            s.executeUpdate();
        } finally {
            try {
                s.close();
            } catch (NullPointerException | SQLException e) {
            }
            try {
                c.close();
            } catch (NullPointerException | SQLException e) {
            }
        }
    }

    private static Connection getConnection() throws SQLException {
        System.out.println("Tyt pizdec");
        return DriverManager.getConnection(jdbcUrl, jdbcUser, jdbcPassword);
    }
}
