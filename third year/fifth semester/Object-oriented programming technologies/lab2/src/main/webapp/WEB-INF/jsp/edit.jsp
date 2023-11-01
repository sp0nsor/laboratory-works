<%@page language="java" contentType="text/html; charset=UTF-8"
        pageEncoding="UTF-8"%>

<%@page import="pckg.TelephoneOperator"%>

<%
    TelephoneOperator call = (TelephoneOperator)request.getAttribute("call");
%>
<HTML>
    <HEAD>
        <META http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <TITLE>Тест JSP</TITLE>
    </HEAD>
    <BODY>
        <FORM action="save.html" method="post">
            <%
                if(call != null) {
            %>
                <INPUT type="hidden" name="id"
                       value="<%= call.getID() %>">
            <%
                }
            %>
            <P>ID:</P>
            <INPUT type="text" name="ID"
                   value="<%= call != null
                              ? call.getID()
                              : new String() %>">
            <P>callerNumber:</P>
            <INPUT type="text" name="callerNumber"
                   value="<%= call != null
                              ? call.getCallerNumber()
                              : new String() %>">
            <P>calledNumber:</P>
                        <INPUT type="text" name="calledNumber"
                               value="<%= call != null
                                          ? call.getCalledNumber()
                                          : new String() %>">
            <P>date:</P>
                        <INPUT type="text" name="date"
                               value="<%= call != null
                                          ? call.getDate()
                                          : new String() %>">
            <P>time:</P>
                        <INPUT type="text" name="time"
                               value="<%= call != null
                                          ? call.getTime()
                                          : new String() %>">
            <P>duration:</P>
                        <INPUT type="text" name="duration"
                               value="<%= call != null
                                          ? call.getDuration()
                                          : new String() %>">
            <P>costOneTariffUnit:</P>
                        <INPUT type="text" name="costOneTariffUnit"
                               value="<%= call != null
                                          ? call.getCostOneTariffUnit()
                                          : new String() %>">
            <P>billingUnit:</P>
                        <INPUT type="text" name="billingUnit"
                               value="<%= call != null
                                          ? call.getBillingUnit()
                                          : new String() %>">
            <P>costCall:</P>
                                    <INPUT type="text" name="costCall"
                                           value="<%= call != null
                                                      ? call.getCostCall()
                                                      : new String() %>">
            <BUTTON type="submit">Сохранить</BUTTON>
            <A href="index.html">Назад</A>
        </FORM>
    </BODY>
</HTML>