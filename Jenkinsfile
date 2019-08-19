import groovy.transform.Field

properties(
    [buildDiscarder(logRotator(numToKeepStr: "10"))]
)

@Field int PENDING   = 0b0000
@Field int SUCCESS   = 0b0001
@Field int FAILURE   = 0b0010
@Field int STAT_FAIL = 0b0100
@Field int DOXY_FAIL = 0b1000

@Field def build_status = [:]
@Field def build = [:]
//@Field def build_notify = [:]

node("ubuntu_16.04&&gcc-arm-none-eabi") {
    stage("Checkout") {
        deleteDir()
        checkout scm
        //setup()
        //parallel build_notify
        sh "git submodule update --init --recursive"
    }
}

//void setup() {
//    def file = readFile("tools/projects.txt")
//    
//    def publish = sh(
//        script: "git log --pretty=oneline -1",
//        returnStdout: true
//    ).contains("[ci publish]")
//    
//    file.replaceAll(".*/", "").split('\n').each {
//        build_status[it] = PENDING
//        build[it] = {
//            lock(it) {
//                try {
//                    sh """#!/bin/bash
//                    set -o pipefail
//                    cd boards/**/${it}
//                    make |& tee ${it}.log
//                    cp boards/**/${it}/build/*.bin ${env.WORKSPACE}/bin
//                    """
//                    build_status[it] |= SUCCESS
//                } catch (e) {
//                    build_status[it] |= FAILURE
//                }
//            }
//        }
//    }
//}

