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

node("ubuntu_16.04&&gcc-arm-none-eabi") {
    stage("Checkout") {
        deleteDir()
        //checkout scm

        //
        // This stuff is necessary for tags to get pulled
        //
        checkout scm: [
            $class: 'GitSCM',
            branches: [[name: "$BRANCH_NAME"]],
            extensions: [[$class: 'CloneOption', noTags: false, shallow: false, depth: 0, reference: '']],
            //userRemoteConfigs: [[credentialsId: '2fe6ce4e-eddc-41c6-af0b-186bbdc71728', refspec: refspec, url: params.url]]
            userRemoteConfigs: [[credentialsId: '2fe6ce4e-eddc-41c6-af0b-186bbdc71728', url: "git@github.com:rfcode/esp-idf.git"]]
        ]

        //setup()
        //parallel build_notify
        sh "git checkout $BRANCH_NAME"
        sh "git submodule update --init --recursive"
    }
}

