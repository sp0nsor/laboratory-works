import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import pckg.TelephoneOperator;

public class SaveServlet extends HttpServlet{
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException{
        req.setCharacterEncoding("UTF-8");
        TelephoneOperator call = new TelephoneOperator();
        call.setID((Integer.parseInt(req.getParameter("ID"))));
        call.setCallerNumber(Integer.parseInt(req.getParameter("calledNumber")));
        call.setCalledNumber(Integer.parseInt(req.getParameter("callerNumber")));
        call.setDate(req.getParameter("date"));
        call.setTime(req.getParameter("time"));
        call.setDuration(Integer.parseInt(req.getParameter("duration")));
        call.setCostOneTariffUnit(Integer.parseInt(req.getParameter("costOneTariffUnit")));
        call.setBillingUnit(Integer.parseInt(req.getParameter("billingUnit")));
        call.setCostCall(call.calculateCost(call.getDuration(), call.getCostOneTariffUnit(), call.getBillingUnit()));

        try{
            call.setID(Integer.parseInt(req.getParameter("id")));
        }catch (NumberFormatException ex) {}
        if(call.getID() == null){
            Storage.create(call);
        }
        else{
            Storage.update(call);
        }
        resp.sendRedirect(req.getContextPath() + "/index.html");
    }

}
