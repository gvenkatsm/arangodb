//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('GIT CC') {
            steps { 
                milestone(1)
                checkout scm
                sh 'pwd'
                sh 'ls -l'
            }
        }

        stage('Build CC LX') { 
            steps { 
                milestone(2)

                // parallel(
                //     'build': {
                        node('linux') {
                            sh 'pwd'
                            sh 'ls -l'
                            sh './Installation/Pipeline/build_cc_lx.sh 16'
                        }
                    // }

                    // 'jslint': {
                    //     node('linux || mac') {
                    //         checkout scm

                    //         script {
                    //             try {
                    //                 sh './Installation/Pipeline/jslint.sh'
                    //             }
                    //             catch (exc) {
                    //                 currentBuild.result = 'UNSTABLE'
                    //             }
                    //         }
                    //     }
                    // }
//                )
            }
        }
    }
}
