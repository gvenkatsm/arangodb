//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('Build CC LX') { 
            steps { 
                milestone(1)

                parallel(
                    'build': {
                        node('linux') {
                            checkout scm

                            sh 'pwd'
                            sh 'ls -l'
                            sh './Installation/Pipeline/build_cc_lx.sh 16'
                        }
                    },

                    'jslint': {
                        node('linux || mac') {
                            checkout scm

                            script {
                                try {
                                    sh './Installation/Pipeline/jslint.sh'
                                }
                                catch (exc) {
                                    currentBuild.result = 'UNSTABLE'
                                }
                            }
                        }
                    }
                )
            }
        }
    }
}
