<?xml version="1.0"?>
<!--********************************************************************************
 * CruiseControl, a Continuous Integration Toolkit
 * Copyright (c) 2001, ThoughtWorks, Inc.
 * 651 W Washington Ave. Suite 600
 * Chicago, IL 60661 USA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     + Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     + Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     + Neither the name of ThoughtWorks, Inc., CruiseControl, nor the
 *       names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior
 *       written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ******************************************************************************
 *
 * 11/7/2006 Draft for use with embUnit framework created by ngWare 
 * (http://ng-embedded.blogspot.com)
 *
 ********************************************************************************-->
<xsl:stylesheet
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:lxslt="http://xml.apache.org/xslt">

    <xsl:output method="html"/>

    <xsl:variable name="testsuite.list" select="//TestRun"/>
    <xsl:variable name="testsuite.error.count" select="count($testsuite.list//FailedTest)"/>
    <xsl:variable name="testcase.list" select="$testsuite.list//Test"/>
    <xsl:variable name="testcase.error.list" select="$testsuite.list//FailedTest"/>
    <xsl:variable name="testcase.failure.list" select="$testsuite.list//failure"/>
    <xsl:variable name="totalErrorsAndFailures" select="count($testcase.error.list) + count($testcase.failure.list)"/>

    <xsl:template match="/" mode="unittests">
        <table align="center" cellpadding="2" cellspacing="0" border="0" width="98%">

            <!-- Unit Tests -->
            <tr>
                <td class="unittests-sectionheader" colspan="4">
                   &#160;Unit Tests: (<xsl:value-of select="count($testcase.list)+ count($testcase.error.list) + count($testcase.failure.list)"/>)
                </td>
            </tr>

            <xsl:choose>
                <xsl:when test="count($testsuite.list) = 0">
                    <tr>
                        <td colspan="2" class="unittests-data">
                            No Tests Run
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2" class="unittests-error">
                            This project doesn't have any tests
                        </td>
                    </tr>
                </xsl:when>

                <xsl:when test="$totalErrorsAndFailures = 0">
                    <tr>
                        <td colspan="4" bgcolor="#00FF00">
                            All Tests Passed
                        </td>
                    </tr>
                </xsl:when>

                <xsl:when test="$totalErrorsAndFailures > 0">
                    <tr>
                        <td colspan="4" bgcolor="#FF0000" >
                            <xsl:value-of select="count($testcase.error.list)"/> Test(s) Failed
                        </td>
                    </tr>

                    <tr/>              

                    <tr class="unittests-title" align="left">
                      <th>Name</th>
                      <th>File</th>
                      <th>Line</th>
                      <th>Message</th>
                    </tr>

                    <xsl:for-each select="$testcase.error.list">
                      <tr>
                        <td><xsl:value-of select="Name"/></td>
                        <td><xsl:value-of select="Location/File"/></td>
                        <td><xsl:value-of select="Location/Line"/></td>
                        <td><xsl:value-of select="Message"/></td>
                      </tr>
                    </xsl:for-each>

                </xsl:when>

            </xsl:choose>

        </table>
    </xsl:template>
</xsl:stylesheet>
