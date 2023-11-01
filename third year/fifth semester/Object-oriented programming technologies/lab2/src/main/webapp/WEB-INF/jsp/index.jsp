<%@page language="java" contentType="text/html; charset=UTF-8"
        pageEncoding="UTF-8"%>

<%@page import="pckg.TelephoneOperator"%>
<%@page import="java.util.Collection"%>

<%
    @SuppressWarnings("unchecked")
    Collection<TelephoneOperator> calls
                   = (Collection<TelephoneOperator>)request.getAttribute("calls");
%>

<HTML>
    <HEAD>
        <META http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <TITLE>Тест JSP</TITLE>
        <STYLE>
            TABLE {
                border-collapse: collapse;
            }
            TH, TD {
                border: 1px solid black;
                padding: 5px 30px 5px 10px;
            }
        </STYLE>
    </HEAD>
    <BODY>
        <FORM action="delete.html" method="post">
            <TABLE>
                <TR>
                    <TH>&nbsp;</TH>
                    <TH>ID</TH>
                    <TH>callerNumber</TH>
                    <TH>calledNumber</TH>
                    <TH>date</TH>
                    <TH>time</TH>
                    <TH>duration</TH>
                    <TH>costOneTariffUnit</TH>
                    <TH>billingUnit</TH>
                    <TH>costCall</TH>
                </TR>
                <%
                    for(TelephoneOperator call : calls) {
                %>
                    <TR>
                        <TD>
                            <INPUT type="checkbox" name="id"
                                   value="<%= call.getID() %>">
                        </TD>
                        <TD>
                            <A href="edit.html?id=<%= call.getID() %>">
                                <%= call.getID() %>
                            </A>
                        </TD>
                        <TD><%= call.getCallerNumber() %></TD>
                        <TD><%= call.getCalledNumber() %></TD>
                        <TD><%= call.getDate() %></TD>
                        <TD><%= call.getTime() %></TD>
                        <TD><%= call.getDuration() %></TD>
                        <TD><%= call.getCostOneTariffUnit() %></TD>
                        <TD><%= call.getBillingUnit() %></TD>
                        <TD><%= call.getCostCall() %></TD>
                    </TR>
                <%
                    }
                %>
            </TABLE>
            <P>
                <A href="edit.html">Добавить</A>
                <BUTTON type="submit">Удалить</BUTTON>
            </P>
        </FORM>
    </BODY>
</HTML>