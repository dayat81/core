/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   coba.c
 * Author: hidayat
 *
 * Created on August 25, 2017, 9:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <freeDiameter/freeDiameter-host.h>
#include <freeDiameter/libfdcore.h>
/*
 * Simple C Test Suite
 */

void
s6a_fd_init (
  void)
{
  struct peer_info                        peer;

  fd_g_debug_lvl = NONE;
  memset (&peer, 0, sizeof (struct peer_info));
  peer.pi_diamid = "hss.test.fr";
  peer.pi_diamidlen = strlen (peer.pi_diamid);
  /*
   * Only SCTP
   */
  peer.config.pic_flags.pro4 = PI_P4_SCTP;
  peer.config.pic_flags.sec = PI_SEC_NONE;
  peer.config.pic_flags.exp = PI_EXP_NONE;
  peer.config.pic_port = 18678;

  if (fd_core_initialize () != 0) {
    printf("fd_core_initialize failed");
  }

  if (fd_core_start () != 0) {
    printf("fd_core_start failed");
  }

  if (fd_core_parseconf ("/usr/local/etc/oai/freeDiameter/hss_fd.conf") != 0) {
    printf("fd_core_waitstartcomplete failed");
  }

  if (fd_core_waitstartcomplete () != 0) {
    printf("fd_core_waitstartcomplete failed");
  }
  //     if (fd_peer_add(&peer, NULL, NULL, NULL) != 0) {
  //         fail("fd_peer_add failed");
  //     }
}
void test1() {
    printf("coba test 1\n");
}

void test2() {
    printf("coba test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (coba) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% coba\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (coba)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (coba) \n");

    printf("%%TEST_STARTED%% test2 (coba)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (coba) \n");

    printf("%%SUITE_FINISHED%% time=0\n");
    s6a_fd_init();
    return (EXIT_SUCCESS);
}
