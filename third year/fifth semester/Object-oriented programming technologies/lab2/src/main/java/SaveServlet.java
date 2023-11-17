import java.io.IOException;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import pckg.TelephoneOperator;

public class SaveServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        TelephoneOperator operator = new TelephoneOperator();
        operator.setCallerNumber(Integer.parseInt(req.getParameter("callerNumber")));
        operator.setCalledNumber(Integer.parseInt(req.getParameter("calledNumber")));
        operator.setDate(req.getParameter("date"));
        operator.setTime(req.getParameter("time"));
        operator.setDuration(Integer.parseInt(req.getParameter("duration")));
        operator.setCostOneTariffUnit(Integer.parseInt(req.getParameter("costOneTariffUnit")));
        operator.setBillingUnit(Integer.parseInt(req.getParameter("billingUnit")));

        try {
            operator.setID(Integer.parseInt(req.getParameter("ID")));
        } catch (NumberFormatException e) {}

        try {
            if (operator.getID() == null) {
                operator.calculateCost(operator.getDuration(), operator.getCostOneTariffUnit(), operator.getBillingUnit());
                Storage.create(operator);
            } else {
                operator.calculateCost(operator.getDuration(), operator.getCostOneTariffUnit(), operator.getBillingUnit());
                Storage.update(operator);
            }
        } catch (SQLException e) {
            throw new ServletException(e);
        }

        resp.sendRedirect(req.getContextPath() + "/index.html");
    }
}
